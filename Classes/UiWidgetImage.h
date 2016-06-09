#ifndef __UIWIDGETIMAGE_H__
#define __UIWIDGETIMAGE_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
class UiWidgetImage : public UiWidgetNode
{
public:
    static UiWidgetImage *create(rapidxml::xml_node<>* node);
    UiWidgetImage(rapidxml::xml_node<>* node);
private:


private:
	cocos2d::CCSprite *m_spr;
};


#endif 
