#pragma once
enum SubMenu {
    MainMenu,
    TestMenu
};
extern SubMenu OnSubMenu;
extern int SubMenuLevel;
extern SubMenu SubMenuArray[1000];
extern int LastOption[999];

bool StringArray(std::string text, std::vector<std::string> Main, int& intg, std::string DEC = "No description.");
bool Float(std::string text, float& Main, float min, float max, float step = 1.f, std::string DEC = "Click C to input value, hold CTRL to scoll FLOAT.");
bool Int(std::string text, int& Main, int min, int max, int step = 1, std::string DEC = "Click C to input value, hold CTRL to scoll INT.");
bool SubOption(std::string text, SubMenu menu, std::string DEC = "No description.");
bool Option(std::string Text, std::string RightText, std::string HelpText = "No description.");
bool Option(std::string Text, std::string HelpText = "No description.");
void End(std::string Menu);

bool IsAtMainMenu();
bool IsClosed();

std::string RoundFloat(float Float, const char* format = "%.4g");
void setDescriptionBox(std::string text, short line = 1);
void BottomBox(std::string text, short line = 1);

void BackSubmenu();
void CloseAllSubMenus();
void NextSubmenu(SubMenu Menu);