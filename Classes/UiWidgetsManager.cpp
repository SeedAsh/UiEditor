#include "UiWidgetsManager.h"
#include "UiWidgetImage.h"
#include "UiWidgetLabel.h"
#include "UiWidgetButton.h"
#include "UiWidgetEmptyBox.h"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include <algorithm>
#include "UiWidgetImageNum.h"
#include "UiWidgetAnimation.h"
USING_NS_CC;
using namespace std;
using namespace std::placeholders;
using namespace rapidxml;

UiWidgetsManager *UiWidgetsManager::theMgr()
{
	static UiWidgetsManager mgr;
	return &mgr;
}

void UiWidgetsManager::addView(IUiWidgetView *view)
{
	auto iter = find(m_views.begin(), m_views.end(), view);
	if (iter == m_views.end())
	{
		m_views.push_back(view);
	}
}

void UiWidgetsManager::removeView(IUiWidgetView *view)
{
	auto iter = find(m_views.begin(), m_views.end(), view);
	if (iter != m_views.end())
	{
		m_views.erase(iter);
	}
}

void UiWidgetsManager::closeCurLayout()
{
	NOTIFY_VIEWS(closeLayout);
	m_maxWidgetId = 0;
	m_xmlPath.clear();
}

void UiWidgetsManager::openNewLayout(string path)
{
	m_maxWidgetId = 0;
	loadXmlFile(path);
}

void UiWidgetsManager::save()
{
	NOTIFY_VIEWS(save, m_xmlPath);
}

void UiWidgetsManager::refresh()
{
	m_maxWidgetId = 0;
	loadXmlFile(m_xmlPath);
}

void UiWidgetsManager::nodeSelected(UiWidgetNode *node)
{
	NOTIFY_VIEWS(nodeSelected, node);
}

void UiWidgetsManager::loadXmlFile(string path)
{
	if (path.empty()) return;

    file<> fdoc(path.c_str());
    std::cout<<fdoc.data()<<std::endl;
    xml_document<> doc;
    doc.parse<0>(fdoc.data());
    
    xml_node<> *layout = doc.first_node();
	if (!checkXml(layout)) return;
	m_xmlPath = path;

	CCSize size;
	size.width = atof(layout->first_attribute("width")->value());
	size.height = atof(layout->first_attribute("height")->value());
	NOTIFY_VIEWS(newLayout, size);

    for(auto node = layout->first_node(); node != NULL; node = node->next_sibling())
    {
        auto iter = m_creaters.find(node->name());
        if(iter != m_creaters.end())
        {
            auto widget = iter->second(node);
            NOTIFY_VIEWS(addNewWidget, widget);
        }
    }
}

void UiWidgetsManager::createWidgetByName(const char *name)
{
	//rapidxml 的路径和cocos的搜索路径不共享
	auto defaultPath = CCFileUtils::sharedFileUtils()->fullPathForFilename("../assets/default.xml");
	//const string defaultPath = "../assets/default.xml";
	file<> fdoc(defaultPath.c_str());
	xml_document<> doc;
	doc.parse<0>(fdoc.data());

	xml_node<> *layout = doc.first_node();
	auto node = layout->first_node(name);

	auto iter = m_creaters.find(name);
	if (iter != m_creaters.end() && node)
	{
		auto widget = iter->second(node);
		NOTIFY_VIEWS(addNewWidget, widget);
	}
}

void UiWidgetsManager::registerWidget(string name, function<UiWidgetNode *(rapidxml::xml_node<>*)> creater)
{
    if(m_creaters.find(name) == m_creaters.end())
    {
        m_creaters.insert(make_pair(name, creater));
    }
}

void UiWidgetsManager::init()
{
    //bind 为什么有时可以省略类名 和this？ vs的特权？
    
    registerWidget("button", bind(&UiWidgetsManager::createButton, this, _1));
    registerWidget("label", bind(&UiWidgetsManager::createLabel, this, _1));
    registerWidget("image", bind(&UiWidgetsManager::createImage, this, _1));
	registerWidget("emptyBox", bind(&UiWidgetsManager::createEmptyBox, this, _1));
	registerWidget("imageNum", bind(&UiWidgetsManager::createImageNum, this, _1));
	registerWidget("animation", bind(&UiWidgetsManager::createAnimation, this, _1));
}

bool UiWidgetsManager::checkXml(rapidxml::xml_node<> *layout)
{
	vector<int> ids;
	for (auto node = layout->first_node(); node != NULL; node = node->next_sibling())
	{
		//检查是否有相同id
		int id = atoi(node->first_node("id")->value());
		auto iter = find(ids.begin(), ids.end(), id);
		if (iter == ids.end())
		{
			ids.push_back(id);
		}
		else
		{
			char str[100] = { 0 };
			sprintf(str, "save id = %d", id);
			CCMessageBox(str, "error!!");
			return false;
		}

		string widgetName = node->name();
		vector<string> files;
		bool fileExit = true;
		if (widgetName == "image")
		{
			string path = node->first_node("path")->value();
			files.push_back(path);
			fileExit = isFilesExit(id, files);
			
		}
		else if (widgetName == "button")
		{
			string path;
			path = node->first_node("normal")->value();
			files.push_back(path);
			path = node->first_node("selected")->value();
			files.push_back(path);
			path = node->first_node("disabled")->value();
			files.push_back(path);
			fileExit = isFilesExit(id, files);
		}
		else if (widgetName == "imageNum")
		{
			string path = node->first_node("path")->value();
			files.push_back(path);
			fileExit = isFilesExit(id, files);
		}
		else if (widgetName == "animation")
		{
			string path = node->first_node("path")->value();
			files.push_back(path);
			fileExit = isFilesExit(id, files);
		}
		if (!fileExit) return false;
	}
	return true;
}

bool UiWidgetsManager::isFilesExit(int id, vector<string> &files)
{
	for (auto iter = files.begin(); iter != files.end(); ++iter)
	{
		//直接用相对路径 在外部exe出错
		string path = "../Resources/";
		path += *iter;
		auto fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
		if (!CCFileUtils::sharedFileUtils()->isFileExist(fullPath))
		{
			char str[100] = { 0 };
			sprintf(str, "id = %d, not found file \"%s\"", id, (*iter).c_str());
			CCMessageBox(str, "error!!");
			return false;
		}
	}
	return true;
}

UiWidgetNode *UiWidgetsManager::createButton(xml_node<> *node)
{
    return UiWidgetButton::create(node);
}

UiWidgetNode *UiWidgetsManager::createLabel(xml_node<> *node)
{
   return UiWidgetLabel::create(node);
}

UiWidgetNode *UiWidgetsManager::createImage(xml_node<> *node)
{
   return UiWidgetImage::create(node);
}

UiWidgetNode *UiWidgetsManager::createEmptyBox(xml_node<> *node)
{
    return UiWidgetEmptyBox::create(node);
}

UiWidgetNode *UiWidgetsManager::createImageNum(xml_node<> *node)
{
	return UiWidgetImageNum::create(node);
}

UiWidgetNode *UiWidgetsManager::createAnimation(xml_node<> *node)
{
	return UiWidgetAnimation::create(node);
}

int UiWidgetsManager::getWidgetId(int id)
{
	if (m_maxWidgetId < id)
	{
		m_maxWidgetId = id;
	}

	if (id == 0)
	{
		return ++m_maxWidgetId;
	}
	else
	{
		return id;
	}
}