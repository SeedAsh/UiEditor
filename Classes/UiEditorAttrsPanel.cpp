#include "UiEditorAttrsPanel.h"

USING_NS_CC;
void UiEditorAttrsPanel::onEnter()
{
	CCNode::onEnter();
	UiWidgetsManager::theMgr()->addView(this);
}

void UiEditorAttrsPanel::onExit()
{
	CCNode::onExit();
	UiWidgetsManager::theMgr()->removeView(this);
}

bool UiEditorAttrsPanel::init()
{
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	m_nameLabel = CCLabelTTF::create("", "Arial", 24);
	m_nameLabel->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.97f));
	addChild(m_nameLabel);
	
	return true;
}

void UiEditorAttrsPanel::newLayout(CCSize &size)
{
	refreshFileName();
}

void UiEditorAttrsPanel::closeLayout()
{
	refreshFileName();
}

void UiEditorAttrsPanel::refreshFileName()
{
	auto fullPath = UiWidgetsManager::theMgr()->getCurFileName();
	auto fileName = fullPath.substr(fullPath.rfind("\\") + 1);
	m_nameLabel->setString(fileName.c_str());
}
