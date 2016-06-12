#ifndef __UIWIDGETSLAYER_H__
#define __UIWIDGETSLAYER_H__

#include "cocos2d.h"
#include "UiWidgetsManager.h"

class UiWidgetsLayout
	: public cocos2d::CCLayer
	, public IUiWidgetView
{
public:
    virtual bool init();  
    CREATE_FUNC(UiWidgetsLayout);
public:
	virtual void addNewWidget(UiWidgetNode *node);
	virtual void save();
	virtual void newLayout(cocos2d::CCSize size);
	virtual void closeLayout();
private:
	void virtual onEnter();
	void virtual onExit();

	void addClippingNode();
	void clearNodes();
	void removeNode(UiWidgetNode *);


private:
	void drawFrame(cocos2d::CCSize &size);
	const int kLayerWidth = 1000;
	const int kLayerHeight = 700;
private:
	std::vector<UiWidgetNode *>m_widgets;
	cocos2d::CCSize m_layoutSize;

};

#endif 
