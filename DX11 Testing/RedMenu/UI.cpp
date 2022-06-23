#pragma once
#include "../IncludeFiles.h"
#include "backend.h"
#include "UI.h"
#include "Menu.h"
#pragma warning(disable : 4996).
extern void Loadimage(const char* ID, const char* FilePath, ImVec2 Pos, ImVec2 Size);
namespace redMenu
{
	float GUI::MenuWidth = 360, GUI::MenuHight = 500, GUI::MenuXpos = 100, GUI::MenuYpos = 120;
	int inputKeyDelay;
	GUI* g_GUI = new GUI();


	void Titleblock()
	{
		if (isMenuOpen)
		{
			float Y;
			if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround + 1) * 25); else Y = ((maxOption + 2) * 25) - 5;
			//Loadimage("Title", "C:\\Users\\gilla\\Desktop\\ETERNITY-HEADER-DONE_1.jpg", { GUI::MenuXpos - 10,  GUI::MenuYpos - 80 }, { (float)GUI::MenuWidth + 15, 90 });
			//Loadimage("e", "C:\\Users\\gilla\\Desktop\\backdropTest.jpg", { GUI::MenuXpos - 10,  GUI::MenuYpos - 80 }, { GUI::MenuWidth, Y });
			g_backend->RectFilled(g_backend->Black, ImVec2(GUI::MenuXpos, GUI::MenuYpos - 27), ImVec2(GUI::MenuWidth, 25));
			g_backend->RectFilled(g_backend->Black, { GUI::MenuXpos,   GUI::MenuYpos - 27 }, { GUI::MenuWidth, 25 }, false, 2.5f);//Line Around

		}
	}
	void BackGround()
	{
		if (isMenuOpen)
		{
			float Y;
			if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround + 1) * 25) - 6; else Y = (maxOption + 1) * 25;
			g_backend->RectFilled(g_backend->BlackLowAlpha, g_backend->Black, g_backend->LowGrey, g_backend->Black, { GUI::MenuXpos, GUI::MenuYpos }, { GUI::MenuWidth, Y });//back colours
			g_backend->RectFilled(g_backend->BlackLowAlpha, g_backend->LowGrey, g_backend->BlackLowAlpha, g_backend->LowGrey, { GUI::MenuXpos, GUI::MenuYpos }, { GUI::MenuWidth, Y });//back coloursExtra
			g_backend->RectFilled(g_backend->LowGrey, { GUI::MenuXpos,  GUI::MenuYpos }, { GUI::MenuWidth, Y });//grey
			g_backend->RectFilled(g_backend->Black, { GUI::MenuXpos,  GUI::MenuYpos }, { GUI::MenuWidth, Y }, false, 2.f);//Line Around1

		}
	}
	int descriptionMenuSize;
	void descriptionMenu(std::string text) {

		float Y;
		if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround - 1) * 25); else Y = ((maxOption - 1) * 25) - 5;
		ImGui::SetNextWindowPos({ (GUI::MenuWidth + GUI::MenuXpos) + 5,  (GUI::MenuYpos + Y) });
		ImGui::SetNextWindowSize(ImVec2(400,  50 * descriptionMenuSize));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, .3));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("descriptionWindow", 0, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
		{
			if (isMenuOpen)
			{
				float win_width = ImGui::GetWindowSize().x;
				float text_width = ImGui::CalcTextSize(text.c_str()).x;
				float text_indentation = (win_width - text_width) * 0.5f;
				float min_indentation = 20.0f;

				if (text_indentation <= min_indentation) {
					text_indentation = min_indentation;
					descriptionMenuSize++;
				}
				ImGui::SameLine(text_indentation);
				ImGui::PushTextWrapPos(win_width - text_indentation);
				ImGui::TextWrapped(text.c_str());
				ImGui::PopTextWrapPos();
				descriptionMenuSize = 0;
			}
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::End();
	
	}

	void setOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = g_backend->TextOnHover, ImVec4 colour2 = g_backend->TextOnNomral)
	{

		g_backend->RectFilled(Hover ? g_backend->Grey : g_backend->ClearColour, ImVec2(TextPos.x - 8, TextPos.y + 2.f), ImVec2(GUI::MenuWidth + 2, 20));
		g_backend->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y + 2.5f });
		g_backend->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 5.f, TextPos.y + 2.5f }, NULL, true);

	}

	bool setOptionTop(std::string text)
	{
		float boxW = 110;
		float xPos = (125 * OptionCountforTopMenu);
		OptionCountforTopMenu++;
		bool HoverMouse, Held;
		bool Hover = currentOptionforTopMenu == OptionCountforTopMenu ? true : false;
		bool pressed = control->MouseClick(StringToChar(text), ImVec2(GUI::MenuXpos + xPos, GUI::MenuYpos - 25), ImVec2(boxW, 25), &HoverMouse, &Held);
		if (Hover || HoverMouse)
		{         
			if (pressed)
				currentOptionforTopMenu = OptionCountforTopMenu;
			g_backend->RectFilled(HoverMouse ? g_backend->RedOrange : g_backend->ChillerRedOrange, ImVec2(GUI::MenuXpos + xPos, GUI::MenuYpos - 25), ImVec2(boxW, 25));
			g_backend->RectFilled(HoverMouse ? g_backend->RedOrange : g_backend->ChillerRedOrange, ImVec2(GUI::MenuXpos + xPos, GUI::MenuYpos - 25), ImVec2(boxW, 25), false, 2.f);
		}
		else
			g_backend->RectFilled(g_backend->ClearColour, ImVec2(GUI::MenuXpos * OptionCountforTopMenu, GUI::MenuYpos - 25), ImVec2(110, 25), false, 2.f);

		ImVec2 TextPos{ GUI::MenuXpos  + xPos, GUI::MenuYpos - 25 };
		g_backend->Text(text, g_backend->White, TextPos, m_font_big);
		return (pressed && HoverMouse) || (scrollTopMenu() && Hover);
	}

	bool GUI::setOption(std::string text, std::string Rtext, std::string DEC)
	{

		OptionCount++;
		OptionCountForBackGround++;
		bool HoverMouse, Held;
		bool Hover = currentOption == OptionCount ? true : false;
		bool pressed = control->MouseClickOption(text, &HoverMouse, &Held);
		
		if (currentOption <= maxOption && OptionCount <= maxOption)
		{
			if (HoverMouse)
				currentOption = OptionCount;
			float YPostion = 25.f * OptionCount - 20;
			ImVec2 TextPos{ GUI::MenuXpos , YPostion + GUI::MenuYpos };
			setOptionText(TextPos, (HoverMouse || Hover), text, Rtext);
		}
		else if (OptionCount > (currentOption - maxOption) && OptionCount <= currentOption)
		{
			if (HoverMouse)
				currentOption = OptionCount;
			float YPostion = 25.f * ((OptionCount - 1) - (currentOption - maxOption));
			ImVec2 TextPos{ GUI::MenuXpos, YPostion + GUI::MenuYpos };
			setOptionText(TextPos, (HoverMouse || Hover), text, Rtext);

		}
		if (DEC == "No description." ? false : Hover)
			descriptionMenu(DEC);
		return (pressed && HoverMouse) || (control->SelectPressed && Hover);
	}

	void GUI::End(std::string SubTitle)
	{

		float YPostion;
		OptionCount >= maxOption ? YPostion = 25.f * maxOption : YPostion = 25.f * (OptionCount);
		std::string Count = std::to_string(currentOption) + "/" + std::to_string(OptionCount);
		ImVec2 TextPos{ (GUI::MenuXpos + 10.f), YPostion + GUI::MenuYpos + 5 };
		g_backend->Text(Count, g_backend->TextOnNomral, TextPos, NULL, true);
		g_backend->Text("V: Red | " + SubTitle, g_backend->TextOnNomral, TextPos);

	}
	std::string optionInputString;

	bool GUI::setOptioninput(std::string text, std::string *output, int maxCharCount)
	{
		#define VK_LSHIFT 0xA0
		const int l_maxCharCount = maxCharCount;
		g_GUI->setOption(text, optionInputString, "");
		if (currentOption == OptionCount)
		{
			if (GetTickCount64() - inputKeyDelay > 125)
			{
				for (auto clicked : g_getKeys)
				{
					if (GetAsyncKeyState(clicked.numericvalue))
					{
						
						if (clicked.key == "BACKSPACE")
						{
							if (optionInputString.length() > 0)
							{
								optionInputString = optionInputString.substr(0, optionInputString.size() - 1);
								inputKeyDelay = GetTickCount64();
							}
							return false;
						}
						if (clicked.key == "ENTER")
						{
							if (optionInputString.length() > 1)
							{
								*output = optionInputString;
								optionInputString = "";
								inputKeyDelay = GetTickCount64();
								return true;
							}
							return false;
						}
						if (optionInputString.length() < l_maxCharCount)
						{
							if (!GetAsyncKeyState(VK_LSHIFT))
							{
								std::string clickKeyString = clicked.key;
								char arr[2];
								strcpy(arr, clickKeyString.c_str());
								optionInputString += std::tolower(arr[0]);
							}
							else
								optionInputString += clicked.key;
							inputKeyDelay = GetTickCount64();
						}
						else
						{
							std::cout << "MAX letters reached";
						}
					}
				}
				
			}
		}
		return false;
	}

	std::string test;
	void GUI::tick()
	{
		ImGui::SetNextWindowPos(ImVec2(g_GUI->MenuXpos - 10, g_GUI->MenuYpos - 120));
		ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 25));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("Background", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus))
		{
			Titleblock();
			if (setOptionTop("Local")){
				g_backend->Main_OnSubMenu = g_backend->Main_Local;
				g_backend->OnSubMenu = g_backend->MainMenu_Local;

			}
			if (setOptionTop("Online")) {
				g_backend->Main_OnSubMenu = g_backend->Main_Online;
				g_backend->OnSubMenu = g_backend->MainMenu_Online;
			}
			if (setOptionTop("Protection")) {
				g_backend->Main_OnSubMenu = g_backend->Main_Protection;
				g_backend->OnSubMenu = g_backend->MainMenu_Protection;
			}
			BackGround();
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::End();
		control->controlTick();
		ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 30));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("MenuWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize ))
		{
			if (isMenuOpen)
			{
				Menu();
				g_GUI->MenuXpos = ImGui::GetWindowPos().x;
				g_GUI->MenuYpos = ImGui::GetWindowPos().y;
			}
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::End();
		OptionCountforTopMenu = 0;
	}



}