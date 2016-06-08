#ifndef __UIEDITORNOTIFIER_H__
#define __UIEDITORNOTIFIER_H__
#include "cocos2d.h"

#define NOTIFY_VIEWS(_FUNC_ ,...)						\
for (size_t index = 0; index < m_views.size(); ++index) \
{														\
	m_views[index]->_FUNC_(__VA_ARGS__);				\
}

class UiWidgetCreator;
struct IUiView
{
	void addNewWidget(UiWidgetCreator *node){}
};

class UiEditorNotifier
{
public:
	static UiEditorNotifier *theNotifier();
	~UiEditorNotifier(){}
public:
	void addView(IUiView *view);
	void removeView(IUiView *view);
private:
	UiEditorNotifier(){}
	
private:
	std::vector<IUiView *> m_views;
	
};
#endif