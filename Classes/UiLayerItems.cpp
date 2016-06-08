#include "UiLayerItems.h"

USING_NS_CC;

void UiLayerItems::onEnter()
{
	CCNode::onEnter();
	UiEditorNotifier::theNotifier()->addView(this);
}

void UiLayerItems::onExit()
{
	CCNode::onExit();
	UiEditorNotifier::theNotifier()->removeView(this);
}

bool UiLayerItems::init()
{

	return true;
}


