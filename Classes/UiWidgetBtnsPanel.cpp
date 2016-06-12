#include "UiWidgetBtnsPanel.h"

USING_NS_CC;

void UiWidgetBtnsPanel::onEnter()
{
	CCNode::onEnter();
	UiEditorNotifier::theNotifier()->addView(this);
}

void UiWidgetBtnsPanel::onExit()
{
	CCNode::onExit();
	UiEditorNotifier::theNotifier()->removeView(this);
}

bool UiWidgetBtnsPanel::init()
{

	return true;
}


