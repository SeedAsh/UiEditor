#include "UiEditLayer.h"

USING_NS_CC;

bool UiEditLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	
	auto spr = CCSprite::create("btn.png");
	addChild(spr);
	return true;
}


