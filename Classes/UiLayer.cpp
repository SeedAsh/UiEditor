#include "UiLayer.h"
#include "UiWidgetBtnsPanel.h"
#include "UiWidgetAttrsPanel.h"
#include "UiWidgetsManager.h"
#include <shlobj.h>

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

	CCMenuItemSprite* closeBtn = getBtnWithLabel("close", menu_selector(UiLayer::onCloseBtnClicked));
	closeBtn->setPosition(ccp(winsize.width * 0.2f, -winsize.height * 0.45f));

	CCMenu *menu = CCMenu::create();
	menu->addChild(updateBtn);
	menu->addChild(saveBtn);
	menu->addChild(openBtn);
	menu->addChild(closeBtn);
	addChild(menu);
	
}

void UiLayer::onUpdateBtnClicked(cocos2d::CCObject* pSender)
{

}

void UiLayer::onSaveBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->save();
}


BOOL hanGetPath()
{
	BROWSEINFO bi;
	LPITEMIDLIST pIDList;
	wchar_t buffer[100] = { 0 };

	//初始化入口参数bi开始
	bi.hwndOwner = CCEGLView::sharedOpenGLView()->getHWnd();
	bi.pidlRoot = NULL;
	bi.pszDisplayName = buffer;//此参数如为NULL则不能显示对话框
	bi.lpszTitle = L"设置文件查找路径";
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	//bi.iImage = IDI_ICON_MAIN;
	bi.lParam = 0;
	pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框
	if (pIDList)
	{
		SHGetPathFromIDList(pIDList, buffer);
		return TRUE;
	}
	return FALSE;
}

void UiLayer::onOpenBtnClicked(cocos2d::CCObject* pSender)
{
	//hanGetPath();
	UiWidgetsManager::theMgr()->test();
}

void UiLayer::onCloseBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->closeCurLayout();
}