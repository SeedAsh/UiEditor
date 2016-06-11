#include "UiWidgetImage.h"
using namespace std;
USING_NS_CC;

UiWidgetImage *UiWidgetImage::create(rapidxml::xml_node<>* node)
{
    UiWidgetImage *img = new UiWidgetImage(node);
    img->autorelease();
    return img;
}


UiWidgetImage::UiWidgetImage(rapidxml::xml_node<>* node)
{
    initBaseInfo(node);
    
    string path = node->first_node("path")->value();
    CCLog(path.c_str());
    m_spr = CCSprite::create(path.c_str());
    CCSize size = m_spr->getContentSize();
    m_spr->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    setContentSize(size);
    addChild(m_spr);
    drawFrame();
}


