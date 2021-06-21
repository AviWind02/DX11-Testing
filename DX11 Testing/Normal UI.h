#pragma once
namespace  Normal_UI
{
    class NormalUI {
    private:
        ImFont* font2;
        ImVec4 MiddleBoxBack = Ui->Black;
        ImVec4 ScrollBar = Ui->LightBlue;
        ImVec4 TextOnNomral = Ui->White;
        ImVec4 TextOnHover = Ui->LightBlue;
        ImVec4 Titlebox = Ui->Black;
        ImVec4 TextInTitleBox = Ui->White;
        ImVec4 BottomEndBox = Ui->Black;
        ImVec4 BottomTextCount = Ui->White;
    public:


        bool MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held)
        {
            ImGuiWindow* window = ImGui::GetCurrentWindow();
            const ImGuiID id = window->GetID(text);
            const ImRect bb(ImVec2(pos.x, pos.y), Ui->add(&ImVec2(pos.x, pos.y), &size));
            return ImGui::ButtonBehavior(bb, id, out_hovered, out_held);
        }
        bool Option(const char* text)
        {
            Ui->OptionCount++;
            bool pressed = false;
            bool Hover; //= currentOption == OptionCount ? true : false;
            bool hovered, held;
            ImGuiWindow* window = ImGui::GetCurrentWindow();

            if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
            {

                float YPostion = 25.f * Ui->OptionCount + 55.f;
                ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };

                const ImGuiID id = window->GetID(text);
                const ImRect bb(ImVec2(TextPos.x, TextPos.y), Ui->add(&ImVec2(TextPos.x, TextPos.y), &ImVec2(400, 25)));
                pressed = ImGui::ButtonBehavior(bb, id, &Hover, &held);


                Ui->RectFilled(MiddleBoxBack, ImVec2(TextPos.x, TextPos.y), ImVec2(400, 25));
                Hover ? Ui->RectFilled(ScrollBar, ImVec2(TextPos.x, TextPos.y), ImVec2(400, 25), false) : Ui->RectFilled(Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(400, 25), false);
                Ui->Text(text, Hover ? TextOnHover : TextOnNomral, { TextPos.x + 10.f, TextPos.y });
            }
            else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
            {
                float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 55.f;
                ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };

                const ImGuiID id = window->GetID(text);
                const ImRect bb(ImVec2(TextPos.x, TextPos.y), Ui->add(&ImVec2(TextPos.x, TextPos.y), &ImVec2(400, 25)));
                pressed = ImGui::ButtonBehavior(bb, id, &Hover, &held);

                Ui->RectFilled(MiddleBoxBack, ImVec2(TextPos.x, TextPos.y), ImVec2(400, 25));
                Hover ? Ui->RectFilled(ScrollBar, ImVec2(TextPos.x, TextPos.y), ImVec2(400, 25), false) : Ui->RectFilled(Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(400, 25), false);
                Ui->Text(text, Hover ? TextOnHover : TextOnNomral, { TextPos.x + 10.f, TextPos.y });
            }

            //if (Hover && SelectPressed)
            return pressed;
            return false;
        }
        std::string SubTitle = "MainMenu";

        void Title(std::string text)
        {
            std::string texttitle = "Spectrum";
            ImVec2 gcsp = ImGui::GetCursorScreenPos();
            ImGui::PushFont(font2);
            float font_size = ImGui::GetFontSize() * texttitle.size() / 2;
            ImGui::PopFont();
            ImVec2 TextPos{ ImGui::GetWindowSize().x / 2 - font_size + (font_size / 2), 20 };
            Ui->RectFilled(BottomEndBox, ImVec2(gcsp.x - 10.f, 0), ImVec2(400, 80));
            //Line(RGBFade(), ImVec2(0, 80), ImVec2(400, 0), 3.f);
            Ui->Text(texttitle, TextOnNomral, TextPos, NULL);
            SubTitle = text;
        }
        void End()
        {

            int OPCount = Ui->OptionCount > 14 ? (15) : Ui->OptionCount + 1;
            std::string Count = Ui->StringToChar(std::to_string(Ui->currentOption) + "/" + std::to_string(Ui->OptionCount));
            float YPostion = 25.f * OPCount + 60.f;
            ImVec2 TextPos{ ImGui::GetCursorScreenPos().x + 10.f, YPostion };
            Ui->RectFilled(BottomEndBox, ImVec2(TextPos.x - 14.f, TextPos.y - 5.f), ImVec2(400, 25));
            Ui->Text(Count, TextOnNomral, { TextPos.x,TextPos.y + 2.f }, NULL, true);
            Ui->Text("V1.0 | " + SubTitle, TextOnNomral, { TextPos.x,TextPos.y + 2.f });
            Ui->Line(Ui->RGBFade(), ImVec2(0, YPostion), ImVec2(400, 0));


        }

    };

    extern NormalUI* UI = new NormalUI();
}