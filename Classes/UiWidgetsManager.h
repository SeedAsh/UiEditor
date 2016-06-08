#ifndef __UIWIDGETSMANAGER_H__
#define __UIWIDGETSMANAGER_H__
#include "cocos2d.h"

#define NOTIFY_VIEWS(_FUNC_ ,...)						\
for (size_t index = 0; index < m_views.size(); ++index) \
{														\
	m_views[index]->_FUNC_(__VA_ARGS__);				\
}

class UiWidgetCreator;
struct IUiWidgetView
{
	virtual void addNewWidget(UiWidgetCreator *creator){}
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

private:
	UiWidgetsManager(){}
private:
	std::vector<IUiWidgetView *> m_views;
	
};
#endif