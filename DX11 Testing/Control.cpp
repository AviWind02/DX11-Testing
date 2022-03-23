#include "IncludeFiles.h"
bool  Control::LeftPressed, Control::RightPressed, Control::SelectPressed, Control::LockMouse, Control::LockNumEdit;
int KeyPressDelay = 150, maxOption = 16, OptionCount, currentOption, OptionCountForBackGround,
KeyPressDelayTickCount = GetTickCount();
bool isMenuOpen = true;
Control* control = new Control();

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
    const ImRect bb(ImVec2(pos.x, pos.y), Blues_UI->add(&pos, &size));
    return ImGui::ButtonBehavior(bb, id, out_hovered, out_held);
}

bool Control::MouseClickOption(std::string text, bool* out_hovered, bool* out_held)
{
    if (currentOption <= maxOption && OptionCount <= maxOption)
    {

        float YPostion = 25.f * OptionCount - 20;
        ImVec2 TextPos{ Blue::MenuXpos, YPostion + Blue::MenuYpos };
        return MouseClick(Blues_UI->StringToChar(text), TextPos, { (blueUI->MenuWidth - 25.f), 25.f }, out_hovered, out_held);
    }
    else if (OptionCount > (currentOption - maxOption) && OptionCount <= currentOption)
    {
        float YPostion = 25.f * ((OptionCount - 1) - (currentOption - maxOption));
        ImVec2 TextPos{ Blue::MenuXpos, YPostion + Blue::MenuYpos };
        return MouseClick(Blues_UI->StringToChar(text), TextPos, { (blueUI->MenuWidth - 25.f), 25.f }, out_hovered, out_held);
    }
    return false;
}

void Control::controlTick()
{
    if (GetTickCount() - KeyPressDelayTickCount > 150)
    {

        if (OpenKey())
        {
            isMenuOpen = !isMenuOpen;
            SubMenuLevel == 0 ? OnSubMenu = SubMenuArray[SubMenuLevel] : OnSubMenu = SubMenuArray[SubMenuLevel];
            KeyPressDelayTickCount = GetTickCount();
        }
        else if (MouseKey())
        {
            LockMouse = !LockMouse;
            KeyPressDelayTickCount = GetTickCount();
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
            if (GetTickCount() - KeyPressDelayTickCount > 50)
            {

                if (ScrollUp())
                {
                    currentOption > 1 ? currentOption-- : currentOption = OptionCount;
                    KeyPressDelayTickCount = GetTickCount();
                }
                else  if (ScrollDown())
                {

                    currentOption < OptionCount ? currentOption++ : currentOption = 1;
                    KeyPressDelayTickCount = GetTickCount();

                }
            }
        }

        if (GetTickCount() - KeyPressDelayTickCount > KeyPressDelay)
        {

            if (UpKey())
            {
                currentOption > 1 ? currentOption-- : currentOption = OptionCount;
                KeyPressDelayTickCount = GetTickCount();
            }
            else  if (DownKey())
            {

                currentOption < OptionCount ? currentOption++ : currentOption = 1;
                KeyPressDelayTickCount = GetTickCount();
            }
            else  if (SelectKey())
            {
                SelectPressed = true;
                KeyPressDelayTickCount = GetTickCount();
            }
            else  if (BackKey())
            {
                BackSubmenu();
                KeyPressDelayTickCount = GetTickCount();
            }
            else if (RightKey())
            {
                RightPressed = true;
                KeyPressDelayTickCount = GetTickCount();
            }
            else  if (LeftKey())
            {
                LeftPressed = true;
                KeyPressDelayTickCount = GetTickCount();
            }


        }
    }
    OptionCount = 0;
    OptionCountForBackGround = 0;

}

std::string StringReturn; bool InputWindowInUse;
std::string KeyboardOnScreen()
{
    InputWindowInUse = true;
    while (InputWindowInUse)
    {
        Control::LockMouse = true;
        //CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(0);
        //WAIT(0);
    }
    InputWindowInUse = false;
    Control::LockMouse = false;
    return StringReturn;
}
void setKeyOnScreen()
{
    if (InputWindowInUse)
    {
        ImGui::SetNextWindowPos(ImVec2(500, 220));
        ImGui::SetNextWindowSize(ImVec2(270, 100));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, Blues_UI->WhiteLowAlpha);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, Blues_UI->BlackLowAlpha);
        ImGui::PushStyleColor(ImGuiCol_Button, Blues_UI->BlackLowAlpha);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
        if (ImGui::Begin("TextWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
        {

            static char Text[255] = "";
            ImGui::Text("Enter value");
            ImGui::InputText("", Text, IM_ARRAYSIZE(Text));
            if (ImGui::Button("Ok", ImVec2(70, 30)))
            {
                StringReturn = Text;
                InputWindowInUse = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel", ImVec2(70, 30)))
            {
                StringReturn = "Unknown";
                InputWindowInUse = false;
            }
        }
        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
        ImGui::PopStyleColor();
        ImGui::PopStyleColor();
        ImGui::End();
    }
}