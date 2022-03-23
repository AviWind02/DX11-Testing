//#pragma once
//namespace TopUI
//{
//	class MenuUI
//	{
//	private:
//		int frametime, frametimeLine;
//		int Closedstate, Openstate = 150, Pushstate = 10;
//		int MenuWidth = 2000, MenuHight;
//		bool OpenMenu = true;
//		std::string RoundFloat(float Float, const char* format = "%.4g")
//		{
//			char NameBuffer[50];
//			sprintf(NameBuffer, format, Float);
//			return (std::string)NameBuffer;
//		}
//		bool MouseClick(const char* text, ImVec2 pos, ImVec2 size, bool* out_hovered, bool* out_held)
//		{
//			ImGuiWindow* window = ImGui::GetCurrentWindow();
//			const ImGuiID id = window->GetID(text);
//			const ImRect bb(ImVec2(pos.x, pos.y), Ui->add(&ImVec2(pos.x, pos.y), &size));
//			return ImGui::ButtonBehavior(bb, id, out_hovered, out_held);
//		}
//		bool MouseClickOption(std::string text, bool* out_hovered, bool* out_held)
//		{
//			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
//			{
//				float YPostion = 25.f * Ui->OptionCount + 5.f;
//				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
//				return MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, out_hovered, out_held);
//			}
//			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
//			{
//				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
//				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
//				return MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, out_hovered, out_held);
//			}
//		}
//
//		void OpenKey()//Also test function
//		{
//			bool one, two;
//			if (MouseClick("RGB BAR", { 0, 0 }, { 7.0f, (float)MenuHight }, &one, &two))
//				OpenMenu = !OpenMenu;
//
//		}
//		void SideLineRGB(float Hight)
//		{
//
//			Ui->Line(Ui->RGBFade(), ImVec2(0, 0), ImVec2(0, Hight), OpenMenu ? 7.f : 12.f);
//		}
//		void BackGround()
//		{
//			Ui->RectFilled(Ui->BlackLowAlpha, { 0, 0 }, { (float)MenuWidth, (float)MenuHight });
//		}
//
//		void EnlargeMenu()
//		{
//			if ((timeGetTime() - frametime) > 10)
//			{
//				if (OpenMenu)
//				{
//					if (MenuHight < Openstate)
//						MenuHight += Pushstate;
//				}
//				else
//				{
//					if (MenuHight > Closedstate)
//						MenuHight -= Pushstate;
//				}
//				frametime = timeGetTime();
//			}
//		}
//		void PlaceOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = Ui->TextOnHover, ImVec4 colour2 = Ui->TextOnNomral)
//		{
//			if (OpenMenu)
//			{
//				//Ui->RectFilled(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(200, 25), false);
//				Ui->Line(Hover ? Ui->ScrollBar : Ui->ClearColour, ImVec2((TextPos.x + 2), TextPos.y), ImVec2((MenuWidth - 25), 0));
//				Ui->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y });
//				Ui->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y }, NULL, true);
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
//				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
//				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
//				PlaceOptionText(TextPos, false, text, Rtext, Ui->WhiteLowAlpha, Ui->WhiteLowAlpha);
//			}
//			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
//			{
//				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
//				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
//				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
//				PlaceOptionText(TextPos, false, text, Rtext, Ui->WhiteLowAlpha, Ui->WhiteLowAlpha);
//			}
//			//ok........ OR statment breaks it
//			Ui->UpKey() && Hover ? Ui->currentOption-- : Ui->DownKey() && Hover ? Ui->currentOption++ : NULL;
//			Ui->ScrollUp() && Hover ? Ui->currentOption-- : Ui->ScrollDown() && Hover ? Ui->currentOption++ : NULL;
//
//			return Hover;
//		}
//		bool Option(std::string text, std::string Rtext)
//		{
//
//			Ui->OptionCount++;
//			bool one, two, pressed = false;
//			bool Hover = Ui->currentOption == Ui->OptionCount ? true : false;
//			if (Ui->currentOption <= Ui->maxOption && Ui->OptionCount <= Ui->maxOption)
//			{
//
//				float YPostion = 25.f * Ui->OptionCount + 5.f;
//				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
//				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
//				PlaceOptionText(TextPos, (one || Hover), text, Rtext);
//			}
//			else if (Ui->OptionCount > (Ui->currentOption - Ui->maxOption) && Ui->OptionCount <= Ui->currentOption)
//			{
//				float YPostion = 25.f * (Ui->OptionCount - (Ui->currentOption - Ui->maxOption)) + 5.f;
//				ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, YPostion };
//				pressed = MouseClick(Ui->StringToChar(text), TextPos, { ((float)MenuWidth - 25.f), 25.f }, &one, &two);
//				PlaceOptionText(TextPos, (one || Hover), text, Rtext);
//
//			}
//
//			if (pressed || (Ui->SelectPressed && Hover))
//				return true;
//			return false;
//		}
//	public:
//		
//		void Backend()
//		{
//			EnlargeMenu();
//			BackGround();
//		  //SideLineRGB(MenuHight);
// 			OpenKey();
//		}
//		int getMenuWidth()
//		{
//			return MenuWidth;
//		}
//		int getMenuHight()
//		{
//			return MenuHight;
//		}
//		bool Option(std::string text)
//		{
//			return Option(text, "");
//		}
//	};
//
//	extern MenuUI* UI = new MenuUI();
//}