#include "UiWidgetButton.h"
#include "UiWidgetsManager.h"
USING_NS_CC;

UiWidgetButton *UiWidgetButton::create(rapidxml::xml_node<>* node)
{
    auto btn = new UiWidgetButton();
    btn->init();
    btn->autorelease();
    return btn;
}

UiWidgetButton *UiWidgetButton::create()
{
    auto btn = new UiWidgetButton();
    btn->init();
    btn->autorelease();
    return btn;
}
bool UiWidgetButton::init()
{
    CCSprite *sp = CCSprite::create("btn.png");
    CCSize size = sp->getContentSize();
    sp->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    setContentSize(size);
    addChild(sp);
	return true;
}

void UiWidgetButton::onTouchBegan()
{
   UiWidgetsManager::theMgr()->test();
}
