#ifndef __UiWidgetButton_H__
#define __UiWidgetButton_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
class UiWidgetButton : public UiWidgetNode
{
public:
	virtual bool init();
    static UiWidgetButton *create(rapidxml::xml_node<>* node);
};

#endif 
