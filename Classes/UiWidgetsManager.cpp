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
    loadXmlFile("default.xml");
    
}

void UiWidgetsManager::loadXmlFile(const char* path)
{
    file<> fdoc(path);
    std::cout<<fdoc.data()<<std::endl;
    xml_document<> doc;
    doc.parse<0>(fdoc.data());
    
    xml_node<> *layout = doc.first_node();

    for(auto node = layout->first_node(); node != NULL; node = node->next_sibling())
    {
        
        auto iter = m_widgets.find(node->name());
        if(iter != m_widgets.end())
        {
            auto widget = iter->second(node);
            NOTIFY_VIEWS(addNewWidget, widget);
        }
    }
}


void UiWidgetsManager::registerWidget(string name, function<UiWidgetNode *(rapidxml::xml_node<>*)> creater)
{
    if(m_widgets.find(name) == m_widgets.end())
    {
        m_widgets.insert(make_pair(name, creater));
    }
}

void UiWidgetsManager::init()
{
    //bind 为什么有时可以省略类名 和this？ vs的特权？
    
    registerWidget("button", bind(&UiWidgetsManager::createButton, this, _1));
    registerWidget("label", bind(&UiWidgetsManager::createLabel, this, _1));
    registerWidget("image", bind(&UiWidgetsManager::createImage, this, _1));
 
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