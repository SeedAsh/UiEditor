#include "UiLayer.h"
#include "UiWidgetBtnsPanel.h"
#include "UiWidgetAttrsPanel.h"
#include "UiWidgetsManager.h"

USING_NS_CC;

bool UiLayer::init()
{
	initBaseBtns();
	addChild(UiWidgetBtnsPanel::create());
	addChild(UiWidgetAttrsPanel::create());
	return true;
}

static CCNode *getBtnSprite(const char *str)
{
	const char* path = "btn.png";
	CCNode *node = CCNode::create();
	auto spr = CCSprite::create(path);
	auto size = spr->getContentSize();
	spr->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
	node->addChild(spr);
	
	CCLabelTTF* pLabel = CCLabelTTF::create(str, "Arial", 24);
	pLabel->setAnchorPoint(ccp(0.5f, 0.5f));
	pLabel->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
	node->addChild(pLabel);

	node->setContentSize(size);
	return node;
}

CCMenuItemSprite *UiLayer::getBtnWithLabel(const char* str, SEL_MenuHandler selector)
{
	CCNode* sItem = getBtnSprite(str);
	CCNode* sSelItem = getBtnSprite(str);
	sSelItem->setScale(1.1f);
	CCMenuItemSprite* menuItem = CCMenuItemSprite::create(sItem, sSelItem, this, selector);
	return menuItem;
}

void UiLayer::initBaseBtns()
{
	auto winsize = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemSprite* updateBtn = getBtnWithLabel("update", menu_selector(UiLayer::onUpdateBtnClicked));
	updateBtn->setPosition(ccp(-winsize.width * 0.1f, -winsize.height * 0.45f));
	CCMenuItemSprite* saveBtn = getBtnWithLabel("save", menu_selector(UiLayer::onSaveBtnClicked));
	saveBtn->setPosition(ccp(winsize.width * 0.0f, -winsize.height * 0.45f));
	CCMenuItemSprite* openBtn = getBtnWithLabel("open", menu_selector(UiLayer::onOpenBtnClicked));
	openBtn->setPosition(ccp(winsize.width * 0.1f, -winsize.height * 0.45f));

	CCMenu *menu = CCMenu::create();
	menu->addChild(updateBtn);
	menu->addChild(saveBtn);
	menu->addChild(openBtn);
	addChild(menu);
	
}

void UiLayer::onUpdateBtnClicked(cocos2d::CCObject* pSender)
{

}

void UiLayer::onSaveBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->save();
}

void UiLayer::onOpenBtnClicked(cocos2d::CCObject* pSender)
{

}