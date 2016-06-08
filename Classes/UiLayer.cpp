#include "UiLayer.h"

USING_NS_CC;

bool UiLayer::init()
{

	auto spr = CCSprite::create("btn.png");
	addChild(spr);
	return true;
}


