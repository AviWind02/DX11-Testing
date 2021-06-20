#pragma once
namespace Simple_UI
{
	class SimpleUI {
	private:

		int frametime;
		int Closedstate, Openstate = 400, Pushstate = 10;
		int MenuWidth;
		bool OpenMenu = true;
		
		void SideLineRGB()
		{
			Ui->Line(Ui->RGBFade(), ImVec2(0, 0), ImVec2(0, 720), 5.0f);
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
		void PlaceOptionText(ImVec2 TextPos, bool Hover, std::string text)
		{
			//Ui->RectFilled(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(200, 25), false);
			Ui->Line(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2((TextPos.x + 2), TextPos.y), ImVec2((MenuWidth - 25), 0));
			Ui->Text(text, Hover ? Ui->TextOnHover : Ui->TextOnNomral, { TextPos.x + 10.f, TextPos.y });
		}
	public:
		bool Option(std::string text)
		{
			Ui->OptionCount++;
			bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
			{
				float YPostion = 25.f * Ui->OptionCount + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				PlaceOptionText(TextPos, Hover, text);
			}
			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
			{
				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
				PlaceOptionText(TextPos, Hover, text);
			}

			if (Hover && Ui->SelectPressed)
				return true;
			return false;
		}
		void Backpart()
		{
			SideLineRGB();
			EnlargeMenu();
			BackGround();

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

		}
	};
	extern SimpleUI* UI = new SimpleUI();

}