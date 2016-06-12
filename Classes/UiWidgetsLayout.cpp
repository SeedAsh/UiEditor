#include "UiWidgetsLayout.h"
#include "UiWidgetImage.h"
#include "UiWidgetsManager.h"
#include "rapidxml/rapidxml_print.hpp"
#include <fstream>

USING_NS_CC;
using namespace std;
using namespace rapidxml;
void UiWidgetsLayout::onEnter()
{
	CCLayer::onEnter();
	UiWidgetsManager::theMgr()->addView(this);
}

void UiWidgetsLayout::onExit()
{
	CCLayer::onExit();
	UiWidgetsManager::theMgr()->removeView(this);
}

bool UiWidgetsLayout::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
    setTouchEnabled(true);
	CCSize size(kLayerWidth, kLayerHeight);
	setContentSize(size);
	ignoreAnchorPointForPosition(false);
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	setPosition(winSize.width * 0.5f, winSize.height * 0.5);
	//addClippingNode();

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"btn.png",
		"btn.png",
		this,
		menu_selector(UiWidgetsLayout::menuCloseCallback));
	auto menu = CCMenu::create(pCloseItem, NULL);
	addChild(menu);
	menu->setPosition(ccp(100, 100));

	drawFrame(size);
	return true;
}

void UiWidgetsLayout::menuCloseCallback(CCObject* pSender)
{
	UiWidgetsManager::theMgr()->test();
}

void UiWidgetsLayout::addClippingNode()
{
	CCLayerColor *back = CCLayerColor::create(ccc4(0, 0, 0, 255));
	back->setContentSize(CCSize(kLayerWidth, kLayerHeight));

	auto clip = CCClippingNode::create(back);
	clip->setInverted(false);
	clip->setAlphaThreshold(0.0f);
	addChild(clip);

	auto spr = CCSprite::create("win.png");

	clip->addChild(spr);
}

void UiWidgetsLayout::drawFrame(CCSize &size)
{
	
	CCPoint leftBottom(0, 0);
	CCPoint leftTop(0, size.height);
	CCPoint rightBottom(size.width, 0);
	CCPoint rightTop(size.width, size.height);

	CCDrawNode *drawNode = CCDrawNode::create();
	addChild(drawNode);

	drawNode->drawSegment(leftBottom, rightBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightBottom, rightTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightTop, leftTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(leftTop, leftBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
}

void UiWidgetsLayout::addNewWidget(UiWidgetNode *node)
{
	addChild(node);
	m_widgets.push_back(node);
}

void UiWidgetsLayout::clearNodes()
{
	m_widgets.clear();
}

void UiWidgetsLayout::removeNode(UiWidgetNode *node)
{
	auto iter = find(m_widgets.begin(), m_widgets.end(), node);
	if (iter != m_widgets.end())
	{
		m_widgets.erase(iter);
	}
}

void UiWidgetsLayout::save()
{
	xml_document<> doc;
	auto layout = doc.allocate_node(node_element, "layout");
	doc.append_node(layout);
	for (auto iter = m_widgets.begin(); iter != m_widgets.end(); ++iter)
	{
		(*iter)->save(doc, layout);
	}
	
	ofstream out("save.xml");
	out << doc;

	out.close();
}

void UiWidgetsLayout::newLayout(CCSize size)
{
	drawFrame(size);
}
