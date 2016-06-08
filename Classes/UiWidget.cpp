#include "UiLayer.h"

USING_NS_CC;

bool UiLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	
	auto spr = CCSprite::create("HelloWorld.png");
	addChild(spr);
	return true;
}


