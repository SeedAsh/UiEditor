#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"

class UiLayer : public cocos2d::CCNode
{
public:
    virtual bool init();  
    CREATE_FUNC(UiLayer);
};

#endif 
