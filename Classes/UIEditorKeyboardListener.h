#ifndef UI_EDITOR_KEYBOARD_LISTENER_H_
#define UI_EDITOR_KEYBOARD_LISTENER_H_

#include "cocos2d.h"
#include <unordered_map>
#include "classes/UIEditorMacros.h"

NS_UI_EDITOR_BEGIN

	
class UIEditorKeyboardListener
{
public:	
	static UIEditorKeyboardListener *sharedListener();

private:
	UIEditorKeyboardListener();
	~UIEditorKeyboardListener();

public:
	bool isKeyDownUp(int keyCode, const std::string &str);
	bool isKeyDown(int keyCode);
	bool isKeyUp(int keyCode);
	void stopKeyInput(bool isStop) { m_stopKeyInput = isStop; }

private:
	std::unordered_map<std::string, std::unordered_map<int, bool> > m_keyState;

private:
	bool m_stopKeyInput;

};

NS_UI_EDITOR_END

#endif