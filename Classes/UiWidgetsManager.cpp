#include "UiWidgetsManager.h"
#include "UiWidgetImage.h"
#include "UiWidgetLabel.h"
#include "UiWidgetButton.h"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include <algorithm>
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

void UiWidgetsManager::test()
{
	//NOTIFY_VIEWS(addNewWidget, &creator);
    CCFileUtils *utils = CCFileUtils::sharedFileUtils();
    string fullPath = utils->fullPathForFilename("layout.xml");
   // string fullPath = "/Users/James/Projects/cocosProj/cocos2d-x-2.2.6/projects/UiEditor/Resources/default.xml";
    loadXmlFile(fullPath.c_str());
}

void UiWidgetsManager::closeCurLayout()
{
	NOTIFY_VIEWS(closeLayout);
	m_maxWidgetId = 0;
}

void UiWidgetsManager::save()
{
	NOTIFY_VIEWS(save);
}

void UiWidgetsManager::loadXmlFile(const char* path)
{
    file<> fdoc(path);
    std::cout<<fdoc.data()<<std::endl;
    xml_document<> doc;
    doc.parse<0>(fdoc.data());
    
    xml_node<> *layout = doc.first_node();
	if (!checkXml(layout)) return;
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
	const string defaultPath = "default.xml";
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
 
}

bool UiWidgetsManager::checkXml(rapidxml::xml_node<> *layout)
{
	vector<int> ids;
	for (auto node = layout->first_node(); node != NULL; node = node->next_sibling())
	{
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
		return m_maxWidgetId;
	}
}