#include "UiWidgetImage.h"
USING_NS_CC;

UiWidgetImage *UiWidgetImage::create(const char *path)
{
	UiWidgetImage *img = new UiWidgetImage(path);
	img->init();
	img->autorelease();
	return img;
}

bool UiWidgetImage::init()
{
	m_spr = CCSprite::create(m_path.c_str());
	CCSize size = m_spr->getContentSize();
	m_spr->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));

	setContentSize(size);
	drawFrame();
	addChild(m_spr);
	return true;
}

UiWidgetNode* ImageCreater::create()
{
	UiWidgetImage *img = new UiWidgetImage(m_path.c_str());
	img->init();
	img->autorelease();

	img->setPosition(m_pos);
	return img;
}

