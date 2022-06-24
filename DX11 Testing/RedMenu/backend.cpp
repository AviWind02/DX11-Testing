#include "../IncludeFiles.h"
#include "backend.h"
#include "UI.h"
namespace redMenu
{
    backend* g_backend = new backend();

    int SubMenuLevel;
    backend::SubMenu SubMenuArray[1000];
    int LastOption[999];


    void backend::NextSubmenu(backend::SubMenu Menu)
    {
        SubMenuArray[SubMenuLevel] = OnSubMenu;
        LastOption[SubMenuLevel] = currentOption;
        SubMenuLevel++;
        OnSubMenu = Menu;
        currentOption = 1;
    }

    void backend::BackSubmenu()
    {
        if (g_backend->OnSubMenu != g_backend->MainMenu_Local 
            && g_backend->OnSubMenu != g_backend->MainMenu_Online 
            && g_backend->OnSubMenu != g_backend->MainMenu_Protection)
        {
            SubMenuLevel--;
            OnSubMenu = SubMenuArray[SubMenuLevel];
            currentOption = LastOption[SubMenuLevel];
        }
    }

    ImVec4 backend::MiddleBoxBack = g_backend->Black;
    
    ImVec4 backend::ScrollBar = {0,0,0,0};//NULL
    ImVec4 backend::TextOnNomral = g_backend->White;
    ImVec4 backend::TextOnHover = g_backend->RedOrange;

    ImVec4 backend::Titlebox = g_backend->Black;
    ImVec4 backend::TextInTitleBox = g_backend->White;

    ImVec4 backend::BottomEndBox = g_backend->Black;
    ImVec4 backend::BottomTextCount = g_backend->White;
    

    std::vector<getKey> g_getKeys
    {
        //Number//
        {0x30, "0"},
        {0x31, "1"},
        {0x32, "2"},
        {0x33, "3"},
        {0x34, "4"},
        {0x35, "5"},
        {0x36, "6"},
        {0x37, "7"},
        {0x38, "8"},
        {0x39, "9"},
        //ABC//
        {0x41,  "A"},
        {0x42,  "B"},
        {0x43,  "C"},
        {0x44,  "D"},
        {0x45,  "E"},
        {0x46,  "F"},
        {0x47,  "G"},
        {0x48,  "H"},
        {0x49,  "I"},
        {0x4A,  "J"},
        {0x4B,  "K"},
        {0x4C,  "L"},
        {0x4D,  "M"},
        {0x4E,  "N"},
        {0x4F,  "O"},
        {0x50,  "P"},
        {0x51,  "Q"},
        {0x52,  "R"},
        {0x53,  "S"},
        {0x54,  "T"},
        {0x55,  "U"},
        {0x56,  "V"},
        {0x57,  "W"},
        {0x58,  "X"},
        {0x59,  "Y"},
        {0x5A,  "Z"},
        //NUMPAD//
        {0x60, "0"},
        {0x61, "1"},
        {0x62, "2"},
        {0x63, "3"},
        {0x64, "4"},
        {0x65, "5"},
        {0x66, "6"},
        {0x67, "7"},
        {0x68, "8"},
        {0x69, "9"},


        //Misc//
        {0x20, " "},//space
        {0x08, "BACKSPACE"},//backspace
        {0x0D, "ENTER"},//backspace
    };

    char* backend::StringToChar(std::string string)
    {
        return _strdup(string.c_str());
    }
    ImVec2 backend::add(ImVec2* vectorA, ImVec2* vectorB) {
        ImVec2 result;
        result.x = vectorA->x;
        result.y = vectorA->y;
        result.x += vectorB->x;
        result.y += vectorB->y;

        return result;
    }

    std::string  backend::getKeyCliked()
    {
   
        return "";
    }

    void backend::Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font, bool Right)
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

    float backend::getRightTextX(float Pos)
    {
        return (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar("Right")).x
            - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos);
    }

    void backend::RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled, float thik, float round)
    {
        ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
        const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));


        if (!Filled)
            ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour), round, 15, thik);
        else
            ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
                ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour));
    }

    void backend::RectFilled(ImVec4 Colour, ImVec4 Colour2, ImVec4 Colour3, ImVec4 Colour4, ImVec2 Pos, ImVec2 Size, bool Filled)
    {
        ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
        const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));


        if (!Filled)
            ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour));
        else
            ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
                ImGui::GetColorU32(Colour2), ImGui::GetColorU32(Colour3), ImGui::GetColorU32(Colour4));
    }
    void backend::Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness, bool Filled)
    {
        ImVec2 size = ImGui::CalcItemSize(ImVec2(rotation.x, rotation.y), 0.0f, 0.0f);
        const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));

        ImGui::GetCurrentWindow()->DrawList->AddLine(bb.Max, bb.Min, ImGui::GetColorU32(Colour), Thinkness);
    }

}