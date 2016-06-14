#ifndef __UIEDITORATTRSPANEL_H__
#define __UIEDITORATTRSPANEL_H__

#include "cocos2d.h"
#include "UiWidgetsManager.h"

class UiEditorAttrsPanel 
	: public cocos2d::CCNode
	, public IUiWidgetView
{
public:
    virtual bool init();  
    CREATE_FUNC(UiEditorAttrsPanel);
private:
	virtual void onEnter();
	virtual void onExit();
	
	virtual void newLayout(cocos2d::CCSize &size);
	virtual void closeLayout();

	void refreshFileName();
private:
	cocos2d::CCLabelTTF *m_nameLabel;
};

#endif 
