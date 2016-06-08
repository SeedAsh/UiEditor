#ifndef __UILAYERATTRS_H__
#define __UILAYERATTRS_H__

#include "cocos2d.h"
#include "UiEditorNotifier.h"

class UiLayerAttrs 
	: public cocos2d::CCNode
	, public IUiView
{
public:
    virtual bool init();  
    CREATE_FUNC(UiLayerAttrs);
private:
	virtual void onEnter();
	virtual void onExit();
};

#endif 
