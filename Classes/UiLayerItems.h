#ifndef __UILAYERITEMS_H__
#define __UILAYERITEMS_H__

#include "cocos2d.h"
#include "UiEditorNotifier.h"

class UiLayerItems
	: public cocos2d::CCNode
	, public IUiView
{
public:
    virtual bool init();  
    CREATE_FUNC(UiLayerItems);
private:
	virtual void onEnter();
	virtual void onExit();
};

#endif 