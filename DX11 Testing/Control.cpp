#include "IncludeFiles.h"
#include"RedMenu/backend.h"
#include "RedMenu/UI.h"
using namespace redMenu;
bool  Control::LeftPressed, Control::RightPressed, Control::SelectPressed, Control::LockMouse, Control::LockNumEdit;
int KeyPressDelay = 150, maxOption = 10, maxOptionforTop = 3, OptionCount, OptionCountforTopMenu, currentOptionforTopMenu, currentOption, OptionCountForBackGround,
KeyPressDelayTickCount = GetTickCount64();
Control* control = new Control();
inline char* StringToChar(std::string string) // Handy little thing
{
    return _strdup(string.c_str());
}
#define IsKeyDown(key) GetAsyncKeyState(key)
bool Forward()
{
    if (GetAsyncKeyState(VK_KEY_W))
        return true;
    return false;
}
bool ShiftL()
{
    if (GetAsyncKeyState(VK_LSHIFT))
        return true;
    return false;
}
bool Backward()
{
    if (GetAsyncKeyState(VK_KEY_S))
        return true;
    return false;
}
bool RightSideward()
{
    if (GetAsyncKeyState(VK_KEY_D))
        return true;
    return false;
}
bool LeftSideward()
{
    if (GetAsyncKeyState(VK_KEY_A))
        return true;
    return false;
}
bool OpenKey()
{
    if (GetAsyncKeyState(VK_F4))
        return true;
    return false;
}
bool MouseKey()
{
    if (GetAsyncKeyState(VK_KEY_X))
        return true;
    return false;
}
bool FavKey()
{
    if (GetAsyncKeyState(VK_KEY_B))
        return true;
    return false;
}
bool Control::MiscKey()
{
    if (GetAsyncKeyState(VK_KEY_C))
        return true;
    return false;
}
bool scrollTopMenu()
{

    if (GetAsyncKeyState(VK_INSERT))
        return true;
    return false;
}
bool UpKey()
{

    if (GetAsyncKeyState(VK_UP))
        return true;
    else if (GetAsyncKeyState(VK_NUMPAD8))
        return true;

    return false;
}
bool Control::ScrollUp()
{

    if (ImGui::GetIO().MouseWheel == 1)
        return true;
    return false;
}
bool Control::ScrollDown()
{
    if (ImGui::GetIO().MouseWheel == -1)
        return true;
    return false;
}
bool DownKey()
{
    if (GetAsyncKeyState(VK_DOWN))
        return true;
    else if (GetAsyncKeyState(VK_NUMPAD2))
        return true;

    return false;
}
bool RightKey()
{
    if (IsKeyDown(VK_RIGHT))
        return true;
    else if (IsKeyDown(VK_NUMPAD6))
        return true;

    return false;
}
bool LeftKey()
{
    if (IsKeyDown(VK_LEFT))
        return true;
    else if (IsKeyDown(VK_NUMPAD4))
        return true;

    return false;
}
bool SelectKey()
{
    if (IsKeyDown(VK_RETURN))
        return true;
    else if (IsKeyDown(VK_NUMPAD5))
        return true;

    return false;
}
bool BackKey()
{
    if (IsKeyDown(VK_BACK))
        return true;
    else if (IsKeyDown(VK_NUMPAD0))
        return true;

    return false;
}
bool Control::MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    const ImGuiID id = window->GetID(text);
    const ImRect bb(ImVec2(pos.x, pos.y), g_backend->add(&pos, &size));
    return ImGui::ButtonBehavior(bb, id, out_hovered, out_held);
}

bool Control::MouseClickOption(std::string text, bool* out_hovered, bool* out_held)
{
    if (currentOption <= maxOption && OptionCount <= maxOption)
    {

        float YPostion = 25.f * OptionCount - 20;
        ImVec2 TextPos{ g_GUI->MenuXpos, YPostion + g_GUI->MenuYpos };
        return MouseClick(StringToChar(text), TextPos, { (g_GUI->MenuWidth - 25.f), 25.f }, out_hovered, out_held);
   
    }
    else if (OptionCount > (currentOption - maxOption) && OptionCount <= currentOption)
    {
        float YPostion = 25.f * ((OptionCount - 1) - (currentOption - maxOption));
        ImVec2 TextPos{ g_GUI->MenuXpos, YPostion + g_GUI->MenuYpos };
        return MouseClick(StringToChar(text), TextPos, { (g_GUI->MenuWidth - 25.f), 25.f }, out_hovered, out_held);
    }
    return false;
}

void Control::controlTick()
{
    if (GetTickCount64() - KeyPressDelayTickCount > 150)
    {

        if (OpenKey())
        {
            isMenuOpen = !isMenuOpen;
           // SubMenuLevel == 0 ? OnSubMenu = SubMenuArray[SubMenuLevel] : OnSubMenu = SubMenuArray[SubMenuLevel];
            KeyPressDelayTickCount = GetTickCount64();
        }
        else if (MouseKey())
        {
            LockMouse = !LockMouse;
            KeyPressDelayTickCount = GetTickCount64();
        }
    }

    if (isMenuOpen)
    {
        IsKeyDown(VK_CONTROL) ? LockNumEdit = true : false;
        RightPressed = false;
        LeftPressed = false;
        SelectPressed = false;
        if (!LockNumEdit)
        {
            if (GetTickCount64() - KeyPressDelayTickCount > 50)
            {

                if (ScrollUp())
                {
                    currentOption > 1 ? currentOption-- : currentOption = OptionCount;
                    KeyPressDelayTickCount = GetTickCount64();
                }
                else  if (ScrollDown())
                {

                    currentOption < OptionCount ? currentOption++ : currentOption = 1;
                    KeyPressDelayTickCount = GetTickCount64();

                }
            }
        }

        if (GetTickCount64() - KeyPressDelayTickCount > KeyPressDelay)
        {
            if (scrollTopMenu())
            {
                
                currentOptionforTopMenu > 1 ? currentOptionforTopMenu-- : currentOptionforTopMenu = OptionCountforTopMenu;
                KeyPressDelayTickCount = GetTickCount64();
            }


            if (UpKey())
            {
                currentOption > 1 ? currentOption-- : currentOption = OptionCount;
                KeyPressDelayTickCount = GetTickCount64();
            }
            else  if (DownKey())
            {

                currentOption < OptionCount ? currentOption++ : currentOption = 1;
                KeyPressDelayTickCount = GetTickCount64();
            }
            else  if (SelectKey())
            {
                SelectPressed = true;
                KeyPressDelayTickCount = GetTickCount64();
            }
            else  if (BackKey())
            {
               // BackSubmenu();
                KeyPressDelayTickCount = GetTickCount64();
            }
            else if (RightKey())
            {
                RightPressed = true;
                KeyPressDelayTickCount = GetTickCount64();
            }
            else  if (LeftKey())
            {
                LeftPressed = true;
                KeyPressDelayTickCount = GetTickCount64();
            }


        }
    }
    OptionCount = 0;
    OptionCountForBackGround = 0;
    ImGui::GetIO().MouseWheel = 0;

}

