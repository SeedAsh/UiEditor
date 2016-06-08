#include "UiWidgetsManager.h"
#include "UiWidgetImage.h"
USING_NS_CC;
using namespace std;
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
	ImageCreater creator;
	creator.setString("win.png");
	creator.setPosition(ccp(300, 300));
	NOTIFY_VIEWS(addNewWidget, &creator);
}

void UiWidgetsManager::loadXmlFile(const char* path)
{
	
}