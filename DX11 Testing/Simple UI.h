#pragma once
namespace Simple_UI
{
	/*
	-2021/06/20(1:35am)-
	* Maybe Keep RGB bar on at all times
	  and when clicked it'll Open : close the menu
	  also allowing users to change its colour would be nice 
	  but yes RGB bar should be the open button and to make it work i need to 
	  the same method i used in Normal Menu for Option clicking, that should do it yes.
	* Look into to simple icon or something like lolicon or keep the main menu the same menu right now
	  If not then i could make the menu go up into the window or keep the side, keeping the side is the best thing tbh.
	*/
	class SimpleUI {
	private:

		int frametime, frametimeLine;
		int Closedstate, Openstate = 325, Pushstate = 10;
		int MenuWidth, MenuHight = 720;
		bool OpenMenu = true;
		bool MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held)
		{
			ImGuiWindow* window = ImGui::GetCurrentWindow();
			const ImGuiID id = window->GetID(text);
			const ImRect bb(ImVec2(pos.x, pos.y), Ui->add(&ImVec2(pos.x, pos.y), &size));
			return ImGui::ButtonBehavior(bb, id, out_hovered, out_held);
		}
		void test()
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
		void PlaceOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "")
		{
			//Ui->RectFilled(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(200, 25), false);
			Ui->Line(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2((TextPos.x + 2), TextPos.y), ImVec2((MenuWidth - 25), 0));
			Ui->Text(text, Hover ? Ui->TextOnHover : Ui->TextOnNomral, { TextPos.x + 10.f, TextPos.y });
			Ui->Text(Rtext, Hover ? Ui->TextOnHover : Ui->TextOnNomral, { TextPos.x + 10.f, TextPos.y }, NULL, true);
			//SideLineRGB(Ui->currentOption * 25.f);
			

		}
		bool Option(std::string text, std::string Rtext)
		{
			Ui->OptionCount++;
			bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
			bool one, two, pressed = false;

			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
			{
				float YPostion = 25.f * Ui->OptionCount + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
				PlaceOptionText(TextPos, one, text, Rtext);
			}
			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
			{
				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				PlaceOptionText(TextPos, Hover, text, Rtext);
			}

			if (pressed)
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
			if(OpenMenu)
				return Option(text, "");
		}
		bool Int(std::string text, int& Main, int min, int max, int step)
		{
			std::string NumberMain = std::to_string(Main);
			std::string NumberMax = std::to_string(max);
			std::string NumberCombo = NumberMain + "/" + NumberMax;
			std::string ShowNumber = "< " + NumberCombo + " >";
			if (Option(text, ShowNumber))
			{
				IsKeyDown(VK_CONTROL) ? Main >= min ? Main -= step : Main = max
					: Main < max ? Main += step : Main = min;
				return true;
			}
			return false;
		}
		void End(std::string SubTitle)
		{
			if (OpenMenu)
			{
				std::string Count = Ui->StringToChar(std::to_string(Ui->currentOption) + "/" + std::to_string(Ui->OptionCount));
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
			test();
		}
		int testInt = 100;
		void TestOption10()
		{
			if (Option("Option One")) std::cout << "Test one\n";
			if (Int("int Option one", testInt, -10, 1000, 2)) std::cout << "Deez NUTS\n";
			Option("Option Two");
			Option("Option Three");
			Option("Option Four");
			Option("Option Five");
			Option("Option Six");
			Option("Option Seven");
			Option("Option Eight");
			Option("Option Nine");
			Option("Option Ten");
			Option("Option 1 One");
			Option("Option 1 Two");
			Option("Option 1 Three");
			Option("Option 1 Four");
			Option("Option 1 Five");
			Option("Option 1 Six");
			Option("Option 1 Seven");
			Option("Option 1 Eight");
			Option("Option 1 Nine");
			Option("Option 1 Ten");
			Option("Option 2 One");
			Option("Option 2 Two");
			Option("Option 2 Three");
			Option("Option 2 Four");
			Option("Option 2 Five");
			Option("Option 3 One");
			Option("Option 3 Two");
			End("Main Menu");

		}
	};
	extern SimpleUI* UI = new SimpleUI();

}