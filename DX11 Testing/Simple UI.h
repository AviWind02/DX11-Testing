#pragma once
namespace Simple_UI
{
	class SimpleUI {
	private:

		int frametime, frametimeLine;
		int Closedstate, Openstate = 325, Pushstate = 10;
		int MenuWidth, MenuHight = 720;
		bool OpenMenu = true;
		
		void SideLineRGB(float Hight)
		{
			
			Ui->Line(Ui->RGBFade(), ImVec2(0, 0), ImVec2(0, Hight), 7.0f);
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
			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
			{
				float YPostion = 25.f * Ui->OptionCount + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				PlaceOptionText(TextPos, Hover, text, Rtext);
			}
			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
			{
				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				PlaceOptionText(TextPos, Hover, text, Rtext);
			}

			if (Hover && Ui->SelectPressed)
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
		void End(std::string SubTitle)
		{
			std::string Count = Ui->StringToChar(std::to_string(Ui->currentOption) + "/" + std::to_string(Ui->OptionCount));
			ImVec2 TextPos{ (ImGui::GetCursorScreenPos().x + 6.f), ((float)MenuHight - 15) };
			Ui->Text(Count, Ui->TextOnNomral, TextPos, NULL, true);
			Ui->Text("V1 | " + SubTitle, Ui->TextOnNomral, TextPos);
		}
		void Backpart()
		{
			EnlargeMenu();
			BackGround();
			SideLineRGB(MenuHight);

		}
		void TestOption10()
		{
			Option("Option One");
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