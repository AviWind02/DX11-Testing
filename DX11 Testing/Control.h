#pragma once
class Control
{

 
public:
	static bool  isMenuOpen, LockMouse, LockNumEdit, LeftPressed, RightPressed, SelectPressed;
	
	void controlTick();
	bool MouseClickOption(std::string text, bool* out_hovered, bool* out_held);
	bool MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held);

};
extern int maxOption, OptionCount, currentOption, OptionCountForBackGround;
extern Control* control;
