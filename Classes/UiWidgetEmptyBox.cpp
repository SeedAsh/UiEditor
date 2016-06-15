#include "UiWidgetEmptyBox.h"
using namespace std;
USING_NS_CC;
using namespace rapidxml;

UiWidgetEmptyBox *UiWidgetEmptyBox::create(rapidxml::xml_node<>* node)
{
    UiWidgetEmptyBox *img = new UiWidgetEmptyBox(node);
    img->autorelease();
    return img;
}


UiWidgetEmptyBox::UiWidgetEmptyBox(rapidxml::xml_node<>* node)
{
    initBaseInfo(node);
	//不用默认的锚点（0.5, 0.5）,而设置为（0,0）
	setAnchorPoint(ccp(0, 0));

    auto greenSpr = CCLayerColor::create(ccc4(0, 255, 0, 80));
    CCSize size = CCSize(50, 50);
    greenSpr->setContentSize(size);
	greenSpr->ignoreAnchorPointForPosition(false);
    auto emptyBox = EmptyBox::create();
    emptyBox->setNode(greenSpr);
    
    setContentSize(size);
    addChild(emptyBox);
    drawFrame();
}

void UiWidgetEmptyBox::save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	auto myNode = doc.allocate_node(node_element, "emptyBox");
	node->append_node(myNode);
	saveBaseInfo(doc, myNode);
}


