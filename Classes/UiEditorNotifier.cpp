#include "UiEditorNotifier.h"
using namespace std;
USING_NS_CC;

UiEditorNotifier *UiEditorNotifier::theNotifier()
{
	static UiEditorNotifier notifier;
	return &notifier;
}

void UiEditorNotifier::addView(IUiView *view)
{
	auto iter = find(m_views.begin(), m_views.end(), view);
	if (iter == m_views.end())
	{
		m_views.push_back(view);
	}
}

void UiEditorNotifier::removeView(IUiView *view)
{
	auto iter = find(m_views.begin(), m_views.end(), view);
	if (iter != m_views.end())
	{
		m_views.erase(iter);
	}
}