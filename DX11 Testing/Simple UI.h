//#pragma once
//extern void Loadimage(const char* ID, const char* FilePath, ImVec2 Pos, ImVec2 Size, ImVec2 Sizep);
//#pragma warning(disable : 4996)
//
//namespace Simple_UI
//{
//	class SimpleUI {
//	private:
//
//		int frametime, frametimeLine;
//		int Closedstate, Openstate = 400, Pushstate = 10;
//		int MenuWidth, MenuHight = 500;
//		float MenuXpos = 100, MenuYpos = 120;
//		bool OpenMenu = true;
//		std::string RoundFloat(float Float, const char* format = "%.4g")
//		{
//			char NameBuffer[50];
//			sprintf(NameBuffer, format, Float);
//			return (std::string)NameBuffer;
//		}
//		void SideLineRGB(float Hight)
//		{
//			Ui->Line(Ui->RGBFade(), ImVec2(0, 0), ImVec2(0, Hight), OpenMenu ? 7.f : 12.f);
//		}
//		int CountOptionsForBack;
//		void Titleblock()
//		{
//
//			Ui->RectFilled(Ui->LowGrey, Ui->BlackLowAlpha, Ui->LowGrey, Ui->BlackLowAlpha, { MenuXpos, MenuYpos - 80 }, { (float)MenuWidth, 80 });//back colours
//			Ui->RectFilled(Ui->BlackLowAlpha, Ui->BlackLowAlpha, Ui->BlackLowAlpha, Ui->LighterBlue, { MenuXpos, MenuYpos - 80 }, { (float)MenuWidth, 80 });//shade
//			Ui->RectFilled(Ui->LowGrey, { MenuXpos,  MenuYpos - 80 }, { (float)MenuWidth, 80 });//grey
//			Ui->RectFilled(Ui->LowGrey, { MenuXpos,  MenuYpos - 80 }, { (float)MenuWidth, 80 });//grey
//			Ui->RectFilled(Ui->LowGrey, { MenuXpos,  MenuYpos - 80 }, { (float)MenuWidth, 80 });//grey
//			Loadimage("Title", "C:\\Users\\gilla\\Desktop\\Logo.png", { MenuXpos - 11,  MenuYpos - 96 }, { (float)MenuWidth, 890 }, { (float)MenuWidth, 90 });
//			Ui->RectFilled(Ui->ScrollBar, { MenuXpos,  MenuYpos - 80 }, { (float)MenuWidth, 80 }, false, 2.f);//Line Around
//		}
//		float testq;
//		void BackGround()
//		{
//			float Y;
//			if (CountOptionsForBack < Ui->maxOption) Y = (float)((CountOptionsForBack + 1) * 25); else Y = (Ui->maxOption + 1)* 25;
//			Ui->RectFilled(Ui->BlackLowAlpha, Ui->LowGrey, Ui->BlackLowAlpha, Ui->LowGrey, { MenuXpos, MenuYpos }, { (float)MenuWidth, Y });//back colours
//			Ui->RectFilled(Ui->BlackLowAlpha, Ui->BlackLowAlpha, Ui->BlackLowAlpha, Ui->LighterBlue, { MenuXpos, MenuYpos }, { (float)MenuWidth, Y });//shade
//			Ui->RectFilled(Ui->LowGrey, { MenuXpos, MenuYpos }, { (float)MenuWidth, Y });//grey
//			Ui->RectFilled(Ui->LowGrey, { MenuXpos, MenuYpos }, { (float)MenuWidth, Y });//grey
//			Ui->RectFilled(Ui->LowGrey, { MenuXpos, MenuYpos }, { (float)MenuWidth, Y });//grey
//			Ui->RectFilled(Ui->ScrollBar, { MenuXpos, MenuYpos }, { (float)MenuWidth, testq }, false, 2.f);//Line Around
//			Float("test", testq, 0, 100, 1);
//			CountOptionsForBack = 0;
//		}
//
//		void EnlargeMenu()
//		{
//
//			OpenMenu ? MenuWidth = Openstate : MenuWidth = Closedstate;
//		}
//		void PlaceOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = Ui->TextOnHover, ImVec4 colour2 = Ui->TextOnNomral)
//		{
//			if (OpenMenu)
//			{
//				//scroll
//				Ui->RectFilled(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(MenuWidth, 20));
//				Ui->RectFilled(Hover ? Ui->Grey : Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(MenuWidth, 20));
//				Ui->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y + 2.5f });
//				Ui->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y + 2.5f }, NULL, true);
//				//SideLineRGB(Ui->currentOption * 25.f);
//			}
//			
//
//		}
//		bool BreakText(std::string text, std::string Rtext)
//		{
//			Ui->OptionCount++;
//			bool one, two, pressed = false;
//			bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
//			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
//			{
//				float YPostion = 25.f * Ui->OptionCount + 5.f;
//				ImVec2 TextPos{ MenuXpos, YPostion };
//				PlaceOptionText(TextPos, false, text, Rtext, Ui->WhiteLowAlpha, Ui->WhiteLowAlpha);
//			}
//			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
//			{
//				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
//				ImVec2 TextPos{ MenuXpos, YPostion };
//				PlaceOptionText(TextPos, false, text, Rtext, Ui->WhiteLowAlpha, Ui->WhiteLowAlpha);
//			}
//			//ok........ OR statment breaks it
//			Ui->UpKey() && Hover ? Ui->currentOption-- : Ui->DownKey() && Hover ? Ui->currentOption++ : NULL;
//			Ui->ScrollUp() && Hover ? Ui->currentOption-- : Ui->ScrollDown() && Hover ? Ui->currentOption++ : NULL;
//			
//			return Hover;
//		}
//		void AddTextPerLine(std::string Text, std::string RText, short line)
//		{
//			float YPostion = 20.f * line;
//			ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, ImGui::GetCursorScreenPos().y + YPostion };
//			Ui->Text(Text, Ui->TextOnNomral, { TextPos.x + 10.f, TextPos.y });
//			Ui->Text(RText, Ui->TextOnNomral, { TextPos.x + 10.f, TextPos.y }, NULL, true);
//
//		}
//		bool Option(std::string text, std::string Rtext)
//		{
//			
//			Ui->OptionCount++;
//			CountOptionsForBack++;
//			bool one, two, pressed = false;
//			bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
//			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
//			{
//
//				float YPostion = 25.f * Ui->OptionCount - 20;
//				ImVec2 TextPos{ MenuXpos, YPostion + MenuYpos };
//				PlaceOptionText(TextPos, Hover, text, Rtext);
//			}
//			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
//			{
//				float YPostion = 25.f * ((Ui->OptionCount - 1) - (Ui->currentOption - Ui->maxOption) );
//				ImVec2 TextPos{ MenuXpos, YPostion + +MenuYpos };
//				PlaceOptionText(TextPos, Hover, text, Rtext);
//
//			}
//
//			if ((Ui->SelectPressed && Hover))
//				return true;
//			return false;
//		}
//	public:
//		int getMenuWidth()
//		{
//			return MenuWidth;
//		}
//		bool Option(std::string text)
//		{
//			return Option(text, "");
//		}
//		bool BreakText(std::string text)
//		{
//			return BreakText("----------------->", text);
//		}
//		bool Toggle(std::string text, bool* toggle)
//		{
//			std::string Toggle = *toggle ? "[-]" : "[O]";
//			if (Option(text, Toggle))
//			{
//				*toggle = !*toggle;
//				return true;
//			}
//			return false;
//		}
//		bool SubMenu(std::string text, UI::SubMenu SubMenu)
//		{
//			if (Option(text, ">"))
//			{
//				Ui->NextSubmenu(SubMenu);
//				return true;
//			}
//			return false;
//		}
//		bool Int(std::string text, int& Main, int min, int max, int step)
//		{
//			bool Held;
//			std::string NumberMain = std::to_string(Main);
//			std::string NumberMax = std::to_string(max);
//			std::string NumberCombo = NumberMain + "/" + NumberMax;
//			std::string ShowNumber = "[" + NumberCombo + "]";
//			if (Option(text, ShowNumber)) return true;
//			Held && Ui->ScrollUp() || Ui->RightPressed && Ui->currentOption == Ui->OptionCount ? Main < max ? Main += step : Main = min : NULL;
//			Held && Ui->ScrollDown() || Ui->LeftPressed && Ui->currentOption == Ui->OptionCount ? Main >= min ? Main -= step : Main = max : NULL;
//			return false;
//
//		}
//		bool Float(std::string text, float& Main, float min, float max, float step)
//		{
//			bool Held;
//			std::string NumberMain = RoundFloat(Main);
//			std::string NumberMax = RoundFloat(max);
//			std::string NumberCombo = NumberMain + "f" + "/" + NumberMax + "f";
//			std::string ShowNumber = "[" + NumberCombo + "]";
//			if (Option(text, ShowNumber)) return true;
//			 Ui->ScrollUp() || Ui->RightPressed && Ui->currentOption == Ui->OptionCount ? Main < max ? Main += step : Main = min : NULL;
//			 Ui->ScrollDown() || Ui->LeftPressed && Ui->currentOption == Ui->OptionCount ? Main >= min ? Main -= step : Main = max : NULL;
//			return false;
//
//		}
//		bool StringArray(std::string text, std::vector<std::string> Main, int& intg)
//		{
//			bool Held;
//			std::string ShowArray = "[" + Main[intg] + "]";
//			if (Option(text, ShowArray)) return true;
//			Held && Ui->ScrollUp() || Ui->RightPressed && Ui->currentOption == Ui->OptionCount ? intg < Main.size() - 1 ? intg += 1 : intg = 0 : NULL;
//			Held && Ui->ScrollDown() || Ui->LeftPressed && Ui->currentOption == Ui->OptionCount ? intg >= 0 ? intg -= 1 : intg = Main.size() - 1 : NULL;
//			return false;
//		}
//		void End(std::string SubTitle)
//		{
//			if (OpenMenu)
//			{
//				float YPostion;
//				if (Ui->OptionCount >= 16)
//					 YPostion = 25.f * 16;
//				else
//					YPostion = 25.f * (Ui->OptionCount);
//
//				std::string Count = "[" + std::to_string(Ui->currentOption) + "/" + std::to_string(Ui->OptionCount) + "]";
//				ImVec2 TextPos{ (MenuXpos + 10.f), YPostion + MenuYpos + 10 };
//				Ui->Text(Count, Ui->TextOnNomral, { (TextPos.x - 4), TextPos.y}, NULL, true);
//				Ui->Text("V1 | " + SubTitle, Ui->TextOnNomral, TextPos);				
//			}
//		}
//		void Backpart()
//		{
//			Titleblock();
//			EnlargeMenu();
//			BackGround();
//		}
//		int testInt = 100;
//		float testFloat = 99.99f;
//		std::string InputTextTest = "Blank";
//		int StringArrayTest;
//		std::vector<std::string> Cars{ "car1", "car2", "car3" };
//		bool TestToggle;
//		UI::SubMenu TestSubMenu;
//		void tick()//max 6 (from 0)
//		{
//			Backpart();
//
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");
//			Option("Test");		
//			End("Test");
//
//
//		}
//
//	};
//	extern SimpleUI* UI = new SimpleUI();
//
//}