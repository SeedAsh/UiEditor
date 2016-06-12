#include "UiWidgetBtnsPanel.h"
#include "UiWidgetsManager.h"

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
	auto winsize = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemSprite* imageBtn = getBtnWithLabel("label", menu_selector(UiWidgetBtnsPanel::onImageBtnClicked));
	imageBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.45f));
	CCMenuItemSprite* buttonBtn = getBtnWithLabel("image", menu_selector(UiWidgetBtnsPanel::onButtonBtnClicked));
	buttonBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.35f));
	CCMenuItemSprite* LabelBtn = getBtnWithLabel("button", menu_selector(UiWidgetBtnsPanel::onLabelBtnClicked));
	LabelBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.25f));

	CCMenu *menu = CCMenu::create();
	menu->addChild(imageBtn);
	menu->addChild(buttonBtn);
	menu->addChild(LabelBtn);
	addChild(menu);

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

CCMenuItemSprite *UiWidgetBtnsPanel::getBtnWithLabel(const char* str, SEL_MenuHandler selector)
{
	CCNode* sItem = getBtnSprite(str);
	CCNode* sSelItem = getBtnSprite(str);
	sSelItem->setScale(1.1f);
	CCMenuItemSprite* menuItem = CCMenuItemSprite::create(sItem, sSelItem, this, selector);
	return menuItem;
}

void UiWidgetBtnsPanel::onLabelBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("label");
}

void UiWidgetBtnsPanel::onButtonBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("button");
}

void UiWidgetBtnsPanel::onImageBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("image");
}
