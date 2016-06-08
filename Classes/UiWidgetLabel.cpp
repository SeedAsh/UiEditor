#include "UiWidgetLabel.h"
USING_NS_CC;

UiWidgetLabel *UiWidgetLabel::create(const char *str)
{
	UiWidgetLabel *label = new UiWidgetLabel(str);
	label->init();
	label->autorelease();
	return label;
}

bool UiWidgetLabel::init()
{
	m_label = CCLabelTTF::create("", "Arial", 24);
	setContentSize(m_label->getContentSize());


	return true;
}

void UiWidgetLabel::setStr(const char *str)
{
	m_label->setString(str);
}


