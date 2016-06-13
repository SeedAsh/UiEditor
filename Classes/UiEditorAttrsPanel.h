#ifndef __UIEDITORATTRSPANEL_H__
#define __UIEDITORATTRSPANEL_H__

#include "cocos2d.h"

class UiEditorAttrsPanel 
	: public cocos2d::CCNode
{
public:
    virtual bool init();  
    CREATE_FUNC(UiEditorAttrsPanel);
private:
	virtual void onEnter();
	virtual void onExit();
};

#endif 
