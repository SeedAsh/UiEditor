#include "UiWidgetsLayer.h"
#include "UiWidgetImage.h"
#include "UiWidgetsManager.h"

USING_NS_CC;
void UiWidgetsLayer::onEnter()
{
	CCLayer::onEnter();
	UiWidgetsManager::theMgr()->addView(this);
}

void UiWidgetsLayer::onExit()
{
	CCLayer::onExit();
	UiWidgetsManager::theMgr()->removeView(this);
}

bool UiWidgetsLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	setContentSize(ccp(kLayerWidth, kLayerHeight));
	ignoreAnchorPointForPosition(false);
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	setPosition(winSize.width * 0.5f, winSize.height * 0.5);
	/*
	auto spr = CCSprite::create("win.png");
	addChild(spr);
	//*/

	//addClippingNode();



	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"btn.png",
		"btn.png",
		this,
		menu_selector(UiWidgetsLayer::menuCloseCallback));
	auto menu = CCMenu::create(pCloseItem, NULL);
	addChild(menu);
	menu->setPosition(ccp(100, 100));

	drawFrame();
	return true;
}

void UiWidgetsLayer::menuCloseCallback(CCObject* pSender)
{
	UiWidgetsManager::theMgr()->test();
}

void UiWidgetsLayer::addClippingNode()
{
	CCLayerColor *back = CCLayerColor::create(ccc4(0, 0, 0, 255));
	back->setContentSize(CCSize(kLayerWidth, kLayerHeight));

	auto clip = CCClippingNode::create(back);
	clip->setInverted(false);
	clip->setAlphaThreshold(0.0f);
	addChild(clip);

	auto spr = CCSprite::create("win.png");

	clip->addChild(spr);
}

void UiWidgetsLayer::drawFrame()
{
	CCSize size = getContentSize();
	CCPoint leftBottom(0, 0);
	CCPoint leftTop(0, size.height);
	CCPoint rightBottom(size.width, 0);
	CCPoint rightTop(size.width, size.height);

	CCDrawNode *drawNode = CCDrawNode::create();
	addChild(drawNode);

	drawNode->drawSegment(leftBottom, rightBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightBottom, rightTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightTop, leftTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(leftTop, leftBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
}

void UiWidgetsLayer::addNewWidget(UiWidgetCreator *creator)
{
	auto node = creator->create();
	addChild(node);
}
