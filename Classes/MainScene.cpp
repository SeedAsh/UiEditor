#include "MainScene.h"
#include "UiLayer.h"
#include "UiWidgetsLayout.h"
#include "UiWidgetsManager.h"
#include "UiWidgetButton.h"
USING_NS_CC;

CCScene* MainScene::scene()
{
	CCScene *scene = CCScene::create();
	MainScene *layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	
	CCLayerColor *bg = CCLayerColor::create(ccc4(60, 60, 60, 255));
	addChild(bg);

    
    UiWidgetsManager::theMgr()->init();
    
	auto uiLayer = UiLayer::create();
	addChild(uiLayer);

	auto layout = UiWidgetsLayout::create();
	addChild(layout);

	/* mac test
	  UiWidgetButton * btn  = UiWidgetButton::create();
	  btn->setPosition(ccp(300, 300));
	  addChild(btn);
	*/
  
	return true;
}


