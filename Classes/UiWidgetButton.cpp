#include "UiWidgetButton.h"
USING_NS_CC;

UiWidgetButton *UiWidgetButton::create(rapidxml::xml_node<>* node)
{
    auto btn = new UiWidgetButton();
    btn->init();
    btn->autorelease();
    return btn;
}

bool UiWidgetButton::init()
{

	return true;
}


