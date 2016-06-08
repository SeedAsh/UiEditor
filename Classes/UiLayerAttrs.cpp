#include "UiLayerAttrs.h"

USING_NS_CC;
void UiLayerAttrs::onEnter()
{
	CCNode::onEnter();
	UiEditorNotifier::theNotifier()->addView(this);
}

void UiLayerAttrs::onExit()
{
	CCNode::onExit();
	UiEditorNotifier::theNotifier()->removeView(this);
}

bool UiLayerAttrs::init()
{
	return true;
}


