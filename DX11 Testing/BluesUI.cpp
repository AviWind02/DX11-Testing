#include "IncludeFiles.h"

 BluesUI* Blues_UI = new BluesUI();



ImVec4 BluesUI::MiddleBoxBack = Blues_UI->Black;
ImVec4 BluesUI::ScrollBar = Blues_UI->LightBlue;
ImVec4 BluesUI::TextOnNomral = Blues_UI->White;
ImVec4 BluesUI::TextOnHover = Blues_UI->LightBlue;
ImVec4 BluesUI::Titlebox = Blues_UI->Black;
ImVec4 BluesUI::TextInTitleBox = Blues_UI->White;
ImVec4 BluesUI::BottomEndBox = Blues_UI->Black;
ImVec4 BluesUI::BottomTextCount = Blues_UI->White;

char* BluesUI::StringToChar(std::string string)
{
    return _strdup(string.c_str());
}
ImVec2 BluesUI::add(ImVec2* vectorA, ImVec2* vectorB) {
    ImVec2 result;
    result.x = vectorA->x;
    result.y = vectorA->y;
    result.x += vectorB->x;
    result.y += vectorB->y;

    return result;
}


void BluesUI::Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font , bool Right)
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

float BluesUI::getRightTextX(float Pos)
{
    return (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar("Right")).x
        - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos);
}

void BluesUI::RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled, float thik, float round)
{
    ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
    const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));


    if (!Filled)
        ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour), round, 15, thik);
    else
        ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
            ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour));
}

void BluesUI::RectFilled(ImVec4 Colour, ImVec4 Colour2, ImVec4 Colour3, ImVec4 Colour4, ImVec2 Pos, ImVec2 Size, bool Filled)
{
    ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
    const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));


    if (!Filled)
        ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour));
    else
        ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
            ImGui::GetColorU32(Colour2), ImGui::GetColorU32(Colour3), ImGui::GetColorU32(Colour4));
}
void BluesUI::Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness, bool Filled)
{
    ImVec2 size = ImGui::CalcItemSize(ImVec2(rotation.x, rotation.y), 0.0f, 0.0f);
    const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));

    ImGui::GetCurrentWindow()->DrawList->AddLine(bb.Max, bb.Min, ImGui::GetColorU32(Colour), Thinkness);
}

