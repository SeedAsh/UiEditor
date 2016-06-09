#ifndef __UIWIDGETLABEL_H__
#define __UIWIDGETLABEL_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
class UiWidgetLabel : public UiWidgetNode
{
public:
	virtual bool init();
	static UiWidgetLabel *create(rapidxml::xml_node<>* node);
	void setStr(const char *str);
private:
	UiWidgetLabel(const char *str): m_str(str){}
private:
	cocos2d::CCLabelTTF *m_label;
	std::string m_str;
};

#endif 
