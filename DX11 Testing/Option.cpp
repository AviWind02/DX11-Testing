#include "IncludeFiles.h"
#pragma warning(disable : 4996).
 SubMenu OnSubMenu = MainMenu;
 int SubMenuLevel;
 SubMenu SubMenuArray[1000];
 int LastOption[999];
void NextSubmenu(SubMenu Menu)
{
    SubMenuArray[SubMenuLevel] = OnSubMenu;
    LastOption[SubMenuLevel] = currentOption;
    SubMenuLevel++;
    OnSubMenu = Menu;
    currentOption = 1;
}
void BackSubmenu()
{
    if (OnSubMenu != MainMenu)
    {
        SubMenuLevel--;
        OnSubMenu = SubMenuArray[SubMenuLevel];
        currentOption = LastOption[SubMenuLevel];
    }
}

bool IsClosed()
{

    return !isMenuOpen;
}

bool IsAtMainMenu()
{
    if (OnSubMenu == MainMenu)
        return true;
    return false;
}

void CloseAllSubMenus()
{
    !isMenuOpen ?
        OnSubMenu = MainMenu :
        SubMenuArray[SubMenuLevel] = OnSubMenu;
}


void End(std::string Menu)
{
    blueUI->End(Menu);
}

bool Option(std::string Text, std::string HelpText )
{
    if (blueUI->setOption(Text, "", HelpText))
        return true;
    return false;
}

bool Option(std::string Text, std::string RightText, std::string HelpText )
{
    if (blueUI->setOption(Text, RightText, HelpText))
        return true;
    return false;
}

bool SubOption(std::string text, SubMenu menu, std::string DEC )
{
    if (Option(text, ">", DEC))
    {
        NextSubmenu(menu);
        return true;
    }
    return false;
}
bool isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
bool Int(std::string text, int& Main, int min, int max, int step, std::string DEC )
{
    bool Held;
    std::string NumberMain = std::to_string(Main);
    std::string NumberMax = std::to_string(max);
    std::string NumberCombo = NumberMain + "/" + NumberMax;
    std::string ShowNumber = "[" + NumberCombo + "]";
    if (Option(text, ShowNumber, DEC)) return true;
    if (currentOption == OptionCount && control->MiscKey())
    {
        std::string num = KeyboardOnScreen();
        if (isNumber(num))
            Main = stoi(num);
        else
            return false;
        return true;
    }
    control->MouseClickOption(text, NULL, &Held);
    return Held && control->ScrollUp() || control->RightPressed && currentOption == OptionCount ? Main < max ? Main += step : Main = min : NULL
        || Held && control->ScrollDown() || control->LeftPressed && currentOption == OptionCount ? Main > min ? Main -= step : Main = max : NULL;
    return false;

}
std::string RoundFloat(float Float, const char* format)// round it to use 0.00 instead of 0.00000000000000
{
    char NameBuffer[50];
    sprintf(NameBuffer, format, Float);
    return (std::string)NameBuffer;
}
bool Float(std::string text, float& Main, float min, float max, float step, std::string DEC )
{
    bool Held;
    std::string NumberMain = RoundFloat(Main);
    std::string NumberMax = RoundFloat(max);
    std::string NumberCombo = NumberMain + "/" + NumberMax;
    std::string ShowNumber = "[" + NumberCombo + "]";
    if (Option(text, ShowNumber, DEC)) return true;
    if (currentOption == OptionCount && control->MiscKey())
    {
        std::string num = KeyboardOnScreen();
        if (isNumber(num))
            Main = stoi(num);
        else
            return false;
       return true;
    }
    control->MouseClickOption(text, NULL, &Held);
    return Held && control->ScrollUp() || control->RightPressed && currentOption == OptionCount ? Main < max ? Main += step : Main = min : NULL
        || Held && control->ScrollDown() || control->LeftPressed && currentOption == OptionCount ? Main > min ? Main -= step : Main = max : NULL;
    return false;

}
bool StringArray(std::string text, std::vector<std::string> Main, int& intg, std::string DEC )
{
    bool Held;
    std::string ShowArray = "[" + Main[intg] + "]";
    if (Option(text, ShowArray, DEC)) return true;
    control->MouseClickOption(text, NULL, &Held);
    return Held && control->ScrollUp() || control->RightPressed && currentOption == OptionCount ? intg < Main.size() - 1 ? intg += 1 : intg = 0 : NULL;
    return Held && control->ScrollDown() || control->LeftPressed && currentOption == OptionCount ? intg >= 0 ? intg -= 1 : intg = Main.size() - 1 : NULL;
    return false;
}
void BottomBox(std::string text, short line)//MAX 6 dont go more then fuck ward
{

    ImGui::SetNextWindowPos(ImVec2(335, 860));
    ImGui::SetNextWindowSize(ImVec2(731, 160));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, .2));
    ImGui::GetStyle().WindowRounding = 3.f;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
    if (ImGui::Begin("HelpBox", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {

        float YPostion = 20.f * line;
        ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, ImGui::GetCursorScreenPos().y + YPostion };
        Blues_UI->Text(text, Blues_UI->TextOnNomral, { TextPos.x + 10.f, TextPos.y });
    }
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
    ImGui::End();
}
void setDescriptionBox(std::string text, short line)//not added in loop but add in imgui loop to show clear box in bottom part of screen for help and other shit idk
{
    BottomBox(text, line);
}
