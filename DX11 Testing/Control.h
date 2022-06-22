#pragma once
class Control
{

 
public:
	static bool LockMouse, LockNumEdit, LeftPressed, RightPressed, SelectPressed;
	
	void controlTick();
	bool MouseClickOption(std::string text, bool* out_hovered, bool* out_held);
	bool MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held);
	bool ScrollDown();
	bool ScrollUp();
	bool MiscKey();

};
extern int KeyPressDelay, maxOption, maxOptionforTop, OptionCount, OptionCountforTopMenu, currentOptionforTopMenu, currentOption, OptionCountForBackGround;
extern bool isMenuOpen; std::string KeyboardOnScreen();

extern Control* control;
