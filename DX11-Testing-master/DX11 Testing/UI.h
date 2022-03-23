#pragma once

class UI {
public:
    const int maxOption = 27;
    int OptionCount;
    int currentOption;
    int RGBFadeRed = 255, RGBFadeGreen = 0, RGBFadeBlue = 0;
    int frametimeRGB;
    ImVec4 RGBFade(int Delay = 5)
    {
        if ((timeGetTime() - frametimeRGB) > Delay)
        {
      
        if (RGBFadeRed > 0 && RGBFadeBlue == 0) {
            RGBFadeRed--;
            RGBFadeGreen++;
        }
        if (RGBFadeGreen > 0 && RGBFadeRed == 0) {
            RGBFadeGreen--;
            RGBFadeBlue++;
        }
        if (RGBFadeBlue > 0 && RGBFadeGreen == 0) {
            RGBFadeRed++;
            RGBFadeBlue--;
        }
            frametimeRGB = timeGetTime();
        }
        return ImColor(RGBFadeRed, RGBFadeGreen, RGBFadeBlue, 255);
    }
    enum SubMenu {
        BLANK,
        MainMenu,
        LocalMenu_SUB,
    };

    int SubMenuLevel;
    SubMenu SubMenuArray[1000];

    SubMenu OnSubMenu = BLANK;
    int IconoptionCount;

    bool LeftPressed;
    bool RightPressed;
    bool SelectPressed;

    void NextSubmenu(SubMenu Menu)
    {
        SubMenuArray[SubMenuLevel] = OnSubMenu;
        SubMenuLevel++;
        OnSubMenu = Menu;
        currentOption = 1;
    }

    void BackSubmenu()
    {
        if (OnSubMenu != BLANK)
        {
            SubMenuLevel--;
            OnSubMenu = SubMenuArray[SubMenuLevel];
            currentOption = 1;
        }
    }

    int KeyPressDelay = 150;
    int KeyPressDelayTickCount = GetTickCount();
#define IsKeyDown(key) GetAsyncKeyState(key)

    bool OpenKey()
    {
        if (GetAsyncKeyState(VK_F9))
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
    bool ScrollUp()
    {

        if (ImGui::GetIO().MouseWheel == 1)
            return true;
        return false;
    }
    bool ScrollDown()
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
    char* StringToChar(std::string string)
    {
        return _strdup(string.c_str());
    }
    ImVec2 add(ImVec2* vectorA, ImVec2* vectorB) {
        ImVec2 result;
        result.x = vectorA->x;
        result.y = vectorA->y;
        result.x += vectorB->x;
        result.y += vectorB->y;

        return result;
    }
  
    bool LockOnHoldForNumChange;
    void control()
    {
        IsKeyDown(VK_CONTROL) ? LockOnHoldForNumChange = true : false;
        RightPressed = false;
        LeftPressed = false;
        SelectPressed = false;
        if (!LockOnHoldForNumChange)
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
            if (OpenKey())
            {
                SubMenuLevel == 0 ? NextSubmenu(MainMenu) : SubMenuLevel == 1 ? BackSubmenu() : NextSubmenu(BLANK);
                KeyPressDelayTickCount = GetTickCount();
            }
            else if (UpKey())
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
        OptionCount = 0;
        IconoptionCount = 0;
    }

   
    const ImVec4 WatermelonRed = ImColor(251, 5, 56, 255);
    const ImVec4 WatermelonPick = ImColor(251, 8, 89, 255);
    const ImVec4 MelonWhite = ImColor(242, 194, 169, 255);
    const ImVec4 MelonWhiteLowAlpha = ImColor(242, 194, 169, 155);
    const ImVec4 MelonSeedBrown = ImColor(73, 49, 9, 255);
    const ImVec4 MelonOrange = ImColor(243, 87, 43, 255);
    const ImVec4 RedColour = ImColor(245, 2, 2, 255);
    const ImVec4 White = ImColor(255, 255, 255, 255);
    const ImVec4 WhiteLowAlpha = ImColor(255, 255, 255, 100);
    const ImVec4 HotPink = ImColor(255, 105, 180, 255);
    const ImVec4 Black = ImColor(0, 0, 0, 255);
    const ImVec4 BlackLowAlpha = ImColor(0, 0, 0, 100);
    const ImVec4 ClearColour = ImColor(0, 0, 0, 0);
    const ImVec4 Orange = ImColor(249, 87, 0, 255);
    const ImVec4 BlueColour = ImColor(0, 164, 204, 255);
    const ImVec4 LightBlue = ImColor(0, 140, 255, 255);
    const ImVec4 OrangeLowAlpha = ImColor(0, 164, 204, 155);
    const ImVec4 BrownSugar = ImColor(160, 120, 85, 255);
    const ImVec4 Beige = ImColor(212, 185, 150, 155);
    const ImVec4 BrownSugarAlpha = ImColor(160, 120, 85, 155);
    const ImVec4 CherryTomato = ImColor(233, 75, 60, 255);
    const ImVec4 PANTONEBlackC = ImColor(45, 41, 38, 255);
    const ImVec4 PANTONEBlackCLowAlpha = ImColor(160, 120, 85, 155);
    const ImVec4 SeaFoam = ImColor(112, 235, 204, 255);
    const ImVec4 DeepAqua = ImColor(0, 59, 70, 255);
    const ImVec4 wave = ImColor(102, 165, 173, 255);
    const ImVec4 DeepAqualowAplha = ImColor(0, 59, 70, 155);
    const ImVec4 BabyBlue = ImColor(137, 207, 240, 255);
    const ImVec4 AcidGreen = ImColor(176, 191, 26, 255);
    const ImVec4 AcidGreenlowAlpha = ImColor(176, 191, 26, 155);
    const ImVec4 DrakPurple = ImColor(133, 22, 233);
    const ImVec4 DrakLimeGreen = ImColor(122, 233, 22);
    const ImVec4 DrakPurpleLowAlpha = ImColor(133, 22, 233, 155);
    const ImVec4 Grey = ImColor(0, 0, 0, 175);

    ImVec4 MiddleBoxBack =Black;
    ImVec4 ScrollBar = LightBlue;
    ImVec4 TextOnNomral =White;
    ImVec4 TextOnHover =LightBlue;
    ImVec4 Titlebox =Black;
    ImVec4 TextInTitleBox =White;
    ImVec4 BottomEndBox =Black;
    ImVec4 BottomTextCount =White;

    void Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font = NULL, bool Right = false)
    {
        if (font == NULL)
            font = ImGui::GetDefaultFont();

        ImGui::PushFont(font);
        if (Right)
            Pos.x = (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar(Text)).x
                - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos.x);

        ImGui::GetCurrentWindow()->DrawList->AddText({ Pos.x , Pos.y }, ImGui::GetColorU32(Colour), Text.c_str());
        ImGui::PopFont();
    }
    float getRightTextX(float Pos)
    {
        return (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar("Right")).x
            - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos);
    }
    void RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled = true)
    {
        ImVec2 POS = { Pos.x, Pos.y };

        ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
        const ImRect bb(ImVec2(Pos.x, Pos.y), add(&POS, &size));


        if (!Filled)
            ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour));
        else
            ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
                ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour));
    }
    void Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness = 1.f, bool Filled = false)
    {
        ImVec2 POS = { Pos.x, Pos.y };
        ImVec2 size = ImGui::CalcItemSize(ImVec2(rotation.x, rotation.y), 0.0f, 0.0f);
        const ImRect bb(POS, add(&POS, &size));

        ImGui::GetCurrentWindow()->DrawList->AddLine(bb.Max, bb.Min, ImGui::GetColorU32(Colour), Thinkness);
    }

};
extern UI* Ui = new UI();

