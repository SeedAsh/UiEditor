#ifndef __UIWIDGETIMAGE_H__
#define __UIWIDGETIMAGE_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"

class UiWidgetImage : public UiWidgetNode
{
public:
    virtual bool init();  
	static UiWidgetImage *create(const char *path);
	UiWidgetImage(const char *path) : m_path(path){}
private:


private:
	cocos2d::CCSprite *m_spr;
	std::string m_path;
};

class ImageCreater : public UiWidgetCreator
{
public:
	virtual UiWidgetNode* create();
	void setString(const char *path){ m_path = path; }
private:
	std::string m_path;
};

#endif 
