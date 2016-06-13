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
	virtual void nodeSelected(UiWidgetNode *node);
private:
	UiWidgetsLayout();
	void virtual onEnter();
	void virtual onExit();

	void addClippingNode();
	void clearNodes();
	void removeNode(UiWidgetNode *);
	virtual void UiWidgetsLayout::update(float dt);

private:
	void drawFrame(cocos2d::CCSize &size);
	const int kLayerWidth = 1000;
	const int kLayerHeight = 800;
private:
	std::vector<UiWidgetNode *>m_widgets;
	cocos2d::CCSize m_layoutSize;
	UiWidgetNode *m_curSelectedNode;
};

#endif 
