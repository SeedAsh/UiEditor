#ifndef __UIWIDGETSLAYER_H__
#define __UIWIDGETSLAYER_H__

#include "cocos2d.h"
#include "UiWidgetsManager.h"

class UiWidgetsLayer
	: public cocos2d::CCLayer
	, public IUiWidgetView
{
public:
    virtual bool init();  
    CREATE_FUNC(UiWidgetsLayer);
public:
	virtual void addNewWidget(UiWidgetCreator *creator);
	void menuCloseCallback(cocos2d::CCObject* pSender);
private:
	void virtual onEnter();
	void virtual onExit();

	void addClippingNode();
private:
	void drawFrame();
	const int kLayerWidth = 1000;
	const int kLayerHeight = 800;

};

#endif 
