#pragma once
#include"RedMenu/backend.h"

bool Option(std::string text, std::string rightText, std::string description);
bool Option(std::string text, std::string description = "No description.");
void End(std::string SubTitle = "Hey, how u doin");
bool StringArray(std::string text, std::vector<std::string> Main, int& intg, bool* toggle, std::string description = "Click to set.", int delay = NULL);
bool StringArray(std::string text, std::vector<std::string> Main, int& intg, std::string description = "Click to set.", int delay = NULL);
bool Float(std::string text, float& Main, float min = 0.f, float max = 99.99f, float step = 0.5f, std::string description = "Click to Enter or use right and left.", bool returnOnSideClick = true, int delay = NULL);
bool Int(std::string text, int& Main, int min = 0, int max = 99, int step = 1, std::string description = "Click to Enter or use right and left.", bool returnOnSideClick = true, int delay = NULL);
bool SubMenu(std::string text, redMenu::backend::SubMenu SubMenu, std::string description = "No description.");
bool Toggle(std::string text, bool* toggle, std::string description = "No description.");
bool OptionKeyInput(std::string option, std::string* ouput, int maxChar = 15);
