#include "../IncludeFiles.h"
#include "backend.h"
#include "UI.h"
namespace redMenu
{
    backend* g_backend = new backend();



    ImVec4 backend::MiddleBoxBack = g_backend->Black;
    
    ImVec4 backend::ScrollBar = {0,0,0,0};//NULL
    ImVec4 backend::TextOnNomral = g_backend->White;
    ImVec4 backend::TextOnHover = g_backend->RedOrange;

    ImVec4 backend::Titlebox = g_backend->Black;
    ImVec4 backend::TextInTitleBox = g_backend->White;

    ImVec4 backend::BottomEndBox = g_backend->Black;
    ImVec4 backend::BottomTextCount = g_backend->White;
    


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