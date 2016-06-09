#ifndef __UIWIDGETSMANAGER_H__
#define __UIWIDGETSMANAGER_H__
#include "cocos2d.h"
#include <functional>
#include <unordered_map>
#include "rapidxml/rapidxml.hpp"


#define NOTIFY_VIEWS(_FUNC_ ,...)						\
for (size_t index = 0; index < m_views.size(); ++index) \
{														\
	m_views[index]->_FUNC_(__VA_ARGS__);				\
}

class UiWidgetNode;

struct IUiWidgetView
{
	virtual void addNewWidget(UiWidgetNode *node){}
};


class UiWidgetsManager
{
public:
	static UiWidgetsManager *theMgr();
	~UiWidgetsManager(){}
	void test();
	void addView(IUiWidgetView *view);
	void removeView(IUiWidgetView *view);
	
	void loadXmlFile(const char* path);
    void init();
  
private:
	UiWidgetsManager(){}
    void registerWidget(std::string name, std::function<UiWidgetNode *(rapidxml::xml_node<>*)> creater);
    UiWidgetNode *createButton(rapidxml::xml_node<> *node);
    UiWidgetNode *createLabel(rapidxml::xml_node<> *node);
    UiWidgetNode *createImage(rapidxml::xml_node<> *node);
private:
	std::vector<IUiWidgetView *> m_views;
    // rapidxml::xml_node<> std::function<void()>
    std::unordered_map<std::string, std::function<UiWidgetNode *(rapidxml::xml_node<>*)> > m_widgets;
};
#endif