#ifndef __UIWIDGETNODE_H__
#define __UIWIDGETNODE_H__

#include "cocos2d.h"

class UiWidgetNode
	: public cocos2d::CCNode
	, public cocos2d::CCTouchDelegate
{
public:
	virtual ~UiWidgetNode(){}
	virtual bool init();
public:
	virtual void save(){}
protected:
	UiWidgetNode(int touchPriority = 0){}
	virtual void onTouchBegan(){}
	void drawFrame();
private:
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
private:
	int m_touchPriority;
	cocos2d::CCPoint m_oldPos;
};

class UiWidgetCreator
{
public:
	virtual UiWidgetNode* create() = 0;
	void setPosition(const cocos2d::CCPoint &pt){ m_pos = pt; }
protected:
	cocos2d::CCPoint m_pos;
	int m_id;
	
};
#endif 
