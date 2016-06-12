#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"

class UiLayer : public cocos2d::CCNode
{
public:
    CREATE_FUNC(UiLayer);
private:
	virtual bool init();
	void initBaseBtns();

	void onUpdateBtnClicked(cocos2d::CCObject* pSender);
	void onSaveBtnClicked(cocos2d::CCObject* pSender);
	void onOpenBtnClicked(cocos2d::CCObject* pSender);
	void onCloseBtnClicked(cocos2d::CCObject* pSender);

	cocos2d::CCMenuItemSprite *UiLayer::getBtnWithLabel(const char* str, cocos2d::SEL_MenuHandler selector);
};

#endif 
