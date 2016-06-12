#include "UiWidgetNode.h"
USING_NS_CC;
using namespace std;
using namespace rapidxml;

bool UiWidgetNode::init()
{
	return true;
}

void UiWidgetNode::onEnter(){
	CCNode::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void UiWidgetNode::onExit(){
	CCNode::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool UiWidgetNode::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	auto pos = convertToNodeSpace(pTouch->getLocation());
	auto size = getContentSize();
	CCRect rect(0, 0, size.width, size.height);
    //test
    onTouchBegan();
	if (rect.containsPoint(pos))
	{
		m_oldPos = getParent()->convertToNodeSpace(pTouch->getLocation());
		onTouchBegan();
		return true;
	}
	return false;
}

void UiWidgetNode::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	auto worldPos = pTouch->getLocation();
	auto curPos = getParent()->convertToNodeSpace(worldPos);
	
	auto offset = ccpSub(curPos, m_oldPos);
	setPosition(ccpAdd(getPosition(), offset));
	m_oldPos = curPos;
}

void UiWidgetNode::drawFrame()
{
	CCSize size = getContentSize();
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

void UiWidgetNode::initBaseInfo(rapidxml::xml_node<> *node)
{
	m_id = atoi(node->first_node("id")->value());
    float x = atof(node->first_node("x")->value());
    float y = atof(node->first_node("y")->value());
    setPosition(ccp(x, y));
}

void UiWidgetNode::saveBaseInfo(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	char str[100] = { 0 };

	sprintf(str, "%d", m_id);
	node->append_node(doc.allocate_node(node_element, "id", doc.allocate_string(str)));

	sprintf(str, "%.02f", getPositionX());
	node->append_node(doc.allocate_node(node_element, "x", doc.allocate_string(str)));

	sprintf(str, "%.02f", getPositionY());
	node->append_node(doc.allocate_node(node_element, "y", doc.allocate_string(str)));
}




