#ifndef __UIWIDGETNODE_H__
#define __UIWIDGETNODE_H__

#include "cocos2d.h"

class UiWidgetNode : public cocos2d::CCNode
{
public:
    virtual bool init();  
    CREATE_FUNC(UiWidgetNode);
};

#endif 
