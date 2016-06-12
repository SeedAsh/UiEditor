#include "UiWidgetAttrsPanel.h"

USING_NS_CC;
void UiWidgetAttrsPanel::onEnter()
{
	CCNode::onEnter();
	UiEditorNotifier::theNotifier()->addView(this);
}

void UiWidgetAttrsPanel::onExit()
{
	CCNode::onExit();
	UiEditorNotifier::theNotifier()->removeView(this);
}

bool UiWidgetAttrsPanel::init()
{
	return true;
}


