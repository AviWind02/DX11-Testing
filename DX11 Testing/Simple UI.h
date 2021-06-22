#pragma once
#pragma warning(disable : 4996)
namespace Simple_UI
{
	class SimpleUI {
	private:

		int frametime, frametimeLine;
		int Closedstate, Openstate = 325, Pushstate = 10;
		int MenuWidth, MenuHight = 720;
		bool OpenMenu = true;
		std::string FloatPoint(float Float, const char* format = "%.4g")
		{
			char NameBuffer[50];
			sprintf(NameBuffer, format, Float);
			return (std::string)NameBuffer;
		}
		bool MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held)
		{
			ImGuiWindow* window = ImGui::GetCurrentWindow();
			const ImGuiID id = window->GetID(text);
			const ImRect bb(ImVec2(pos.x, pos.y), Ui->add(&ImVec2(pos.x, pos.y), &size));
			return ImGui::ButtonBehavior(bb, id, out_hovered, out_held);
		}
		bool MouseClickOption(std::string text, bool* out_hovered, bool* out_held)
		{
			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
			{
				float YPostion = 25.f * Ui->OptionCount + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				return MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, out_hovered, out_held);
			}
			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
			{
				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				return MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, out_hovered, out_held);
			}
		}
		void OpenKey()//Also test function
		{
			bool one, two;
			if (MouseClick("RGB BAR", { 0, 0 }, { 7.0f, (float)MenuHight }, &one, &two))
				OpenMenu = !OpenMenu;
		}
		void SideLineRGB(float Hight)
		{
			
			Ui->Line(Ui->RGBFade(), ImVec2(0, 0), ImVec2(0, Hight), OpenMenu ? 7.f : 12.f);
		}
		void BackGround()
		{
			Ui->RectFilled(Ui->BlackLowAlpha, { 0, 0 }, { (float)MenuWidth, 720 });
		}

		void EnlargeMenu()
		{
			if ((timeGetTime() - frametime) > 10)
			{
				if (OpenMenu)
				{
					if (MenuWidth < Openstate)
						MenuWidth += Pushstate;
				}
				else
				{
					if (MenuWidth > Closedstate)
						MenuWidth -= Pushstate;
				}
				frametime = timeGetTime();
			}
		}
		void PlaceOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = Ui->TextOnHover, ImVec4 colour2 = Ui->TextOnNomral)
		{
			if (OpenMenu)
			{
				//Ui->RectFilled(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(200, 25), false);
				Ui->Line(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2((TextPos.x + 2), TextPos.y), ImVec2((MenuWidth - 25), 0));
				Ui->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y });
				Ui->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y }, NULL, true);
				//SideLineRGB(Ui->currentOption * 25.f);
			}
			

		}
		bool BreakText(std::string text, std::string Rtext)
		{
			Ui->OptionCount++;
			bool one, two, pressed = false;
			bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
			//Ui->UpKey() ? Ui->currentOption + 1 : NULL;
			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
			{
				float YPostion = 25.f * Ui->OptionCount + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
				PlaceOptionText(TextPos, false, text, Rtext, Ui->WhiteLowAlpha, Ui->WhiteLowAlpha);
			}
			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
			{
				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
				PlaceOptionText(TextPos, false, text, Rtext, Ui->WhiteLowAlpha, Ui->WhiteLowAlpha);
			}
			
			if (pressed || (Ui->SelectPressed && Hover))
				return true;
			return false;
		}
		bool Option(std::string text, std::string Rtext)
		{
			
				Ui->OptionCount++;
				bool one, two, pressed = false;
				bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
				if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
				{

					float YPostion = 25.f * Ui->OptionCount + 5.f;
					ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
					pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
					PlaceOptionText(TextPos, (one || Hover), text, Rtext);
				}
				else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
				{
					float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
					ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
					pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
					PlaceOptionText(TextPos, (one || Hover), text, Rtext);

				}

			if (pressed || (Ui->SelectPressed && Hover))
				return true;
			return false;
		}
	public:
		int getMenuWidth()
		{
			return MenuWidth;
		}
		bool Option(std::string text)
		{
				return Option(text, "");
		}
		bool BreakText(std::string text)
		{
			return BreakText("-----------------", text);
		}
		bool Int(std::string text, int& Main, int min, int max, int step)
		{
			bool Held;
			std::string NumberMain = std::to_string(Main);
			std::string NumberMax = std::to_string(max);
			std::string NumberCombo = NumberMain + "/" + NumberMax;
			std::string ShowNumber = "[" + NumberCombo + "]";
			if (Option(text, ShowNumber)) return true;
			MouseClickOption(text, NULL, &Held);
			Held && Ui->ScrollUp() || Ui->RightPressed && Ui->currentOption == Ui->OptionCount ? Main < max ? Main += step : Main = min : NULL;
			Held && Ui->ScrollDown() || Ui->LeftPressed && Ui->currentOption == Ui->OptionCount ? Main >= min ? Main -= step : Main = max : NULL;
			return false;

		}
		bool Float(std::string text, float& Main, float min, float max, float step)
		{
			bool Held;
			std::string NumberMain = FloatPoint(Main);
			std::string NumberMax = FloatPoint(max);
			std::string NumberCombo = NumberMain+"f" + "/" + NumberMax + "f";
			std::string ShowNumber = "[" + NumberCombo + "]";
			if (Option(text, ShowNumber)) return true;
			MouseClickOption(text, NULL, &Held);
			Held&& Ui->ScrollUp() || Ui->RightPressed && Ui->currentOption == Ui->OptionCount ? Main < max ? Main += step : Main = min : NULL;
			Held&& Ui->ScrollDown() || Ui->LeftPressed && Ui->currentOption == Ui->OptionCount ? Main >= min ? Main -= step : Main = max : NULL;
			return false;

		}
		void End(std::string SubTitle)
		{
			if (OpenMenu)
			{
				std::string Count = "[" + std::to_string(Ui->currentOption) + "/" + std::to_string(Ui->OptionCount) + "]";
				ImVec2 TextPos{ (ImGui::GetCursorScreenPos().x + 6.f), ((float)MenuHight - 15) };
				Ui->Text(Count, Ui->TextOnNomral, TextPos, NULL, true);
				Ui->Text("V1 | " + SubTitle, Ui->TextOnNomral, TextPos);
			}
		}
		void Backpart()
		{
			EnlargeMenu();
			BackGround();
			SideLineRGB(MenuHight);
			OpenKey();
		}
		int testInt = 100;
		float testFloat = 99.99f;

		void TestOption10()
		{
			if (Option("Option 1")) std::cout << "Test one\n";
			if (Int("int", testInt, -10, 1000, 2)) std::cout << "Deez NUTS\n";
			if (Float("Float", testFloat, -10.f, 99.99f, 2.f)) std::cout << "Deez NUTS oui\n";
			if (BreakText("Break Text")) std::cout << "zlex = gay?\n";
			Option("Option 2");
			Option("Option 3");
			Option("Option 4");
			Option("Option 5");
			Option("Option 6");
			Option("Option 7");
			Option("Option 8");
			Option("Option 9");
			Option("Option 10");
			Option("Option 11");
			Option("Option 12");
			Option("Option 13");
			Option("Option 14");
			Option("Option 15");
			Option("Option 16");
			Option("Option 17");
			Option("Option 18");
			Option("Option 19");
			Option("Option 20");
			Option("Option 21");
			Option("Option 22");
			Option("Option 23");
			Option("Option 24");
			Option("Option 25");
			Option("Option 26");
			Option("Option 27");
			Option("Option 28");
			Option("Option 29");
			Option("Option 30");
			Option("Option 31");
			Option("Option 32");
			End("Main Menu");

		}
	};
	extern SimpleUI* UI = new SimpleUI();

}