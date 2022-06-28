#pragma once
#include "../IncludeFiles.h"
#include "GUI.h"
#include "Menu.h"
#include "backend.h"
#pragma warning(disable : 4996).
extern void Loadimage(const char* FilePath, ImVec2 Size);
extern ImFont* m_font, * m_font_big, *m_font_title;
namespace summer
{
	GUI* g_GUI;
	float GUI::MenuWidth = 365, GUI::MenuHight = 500, GUI::MenuXpos, GUI::MenuYpos;
	bool swapSidesfordescription;
	void openBlock()
	{
		
	}
	int descriptionMenuSize;
	void descriptionMenu(std::string text) {

		float Y;
		if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround - 1) * 25); else Y = ((maxOption - 1) * 25) - 5;
		ImGui::SetNextWindowPos({ ((swapSidesfordescription || (GUI::MenuXpos > 950) ? (-GUI::MenuWidth) - 45 : GUI::MenuWidth + 5) + GUI::MenuXpos),  (GUI::MenuYpos + Y)});
		ImGui::SetNextWindowSize(ImVec2(400, 50 * descriptionMenuSize));
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
	void Titleblock()
	{
		if (isMenuOpen)
		{
			float Y;
			if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround + 1) * 25); else Y = ((maxOption + 2) * 25) - 5;

			g_GUI->RectFilled(g_backend->Black, { GUI::MenuXpos,  GUI::MenuYpos - 125 }, { GUI::MenuWidth, 100 });
			g_GUI->RectFilled(g_backend->Black, { GUI::MenuXpos,   GUI::MenuYpos - 125 }, { GUI::MenuWidth, 100 }, false, 2.5f);//Line Around
			g_GUI->Text("Spectrum", g_backend->White, { GUI::MenuXpos,   GUI::MenuYpos - 100 }, m_font_title, false, true);
			Loadimage("C:\\Spectrum\\Header.jpg", { GUI::MenuWidth, 100 });
			g_GUI->Line(g_backend->White, { GUI::MenuXpos,  GUI::MenuYpos - 30 }, { GUI::MenuWidth , 0 });
			g_GUI->RectFilled(g_backend->Black, ImVec2(GUI::MenuXpos, GUI::MenuYpos - 27), ImVec2(GUI::MenuWidth, 25));
			g_GUI->RectFilled(g_backend->Black, { GUI::MenuXpos,   GUI::MenuYpos - 27 }, { GUI::MenuWidth, 25 }, false, 2.5f);//Line Around

		}
	}
	void BackGround()
	{
		if (isMenuOpen)
		{
			float Y;
			if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround + 2) * 25) - 6; else Y = (maxOption + 2) * 25;
			g_GUI->RectFilled(g_backend->BlackLowAlpha, g_backend->Black, g_backend->LowGrey, g_backend->Black, { GUI::MenuXpos, GUI::MenuYpos }, { GUI::MenuWidth, Y });//back colours
			g_GUI->RectFilled(g_backend->BlackLowAlpha, g_backend->LowGrey, g_backend->BlackLowAlpha, g_backend->LowGrey, { GUI::MenuXpos, GUI::MenuYpos }, { GUI::MenuWidth, Y });//back coloursExtra
			g_GUI->RectFilled(g_backend->LowGrey, { GUI::MenuXpos,  GUI::MenuYpos }, { GUI::MenuWidth, Y });//grey
			g_GUI->RectFilled(g_backend->Black, { GUI::MenuXpos,  GUI::MenuYpos }, { GUI::MenuWidth, Y }, false, 2.f);//Line Around1

		}
	}
	void setOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = g_backend->TextOnHover, ImVec4 colour2 = g_backend->TextOnNomral)
	{

		g_GUI->RectFilled(Hover ? g_backend->Grey : g_backend->ClearColour, ImVec2(TextPos.x, TextPos.y + 2.f), ImVec2(GUI::MenuWidth, 20));
		g_GUI->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y + 2.5f });
		g_GUI->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 5.f, TextPos.y + 2.5f }, NULL, true);

	}
	std::string Sub;
	bool setOptionTop()
	{
		float boxW = 110;
		float xPos = (125 * OptionCountforTopMenu);
		OptionCountforTopMenu++;
		bool HoverMouse, Held;
		bool Hover = currentOptionforTopMenu == OptionCountforTopMenu ? true : false;
		bool pressed = control->MouseClick(StringToChar(Sub), ImVec2(GUI::MenuXpos + xPos, GUI::MenuYpos - 25), ImVec2(boxW, 25), &HoverMouse, &Held);
	/*	if (Hover || HoverMouse)
		{
			if (pressed)
				currentOptionforTopMenu = OptionCountforTopMenu;
			g_GUI->RectFilled(HoverMouse ? g_backend->RedOrange : g_backend->ChillerRedOrange, ImVec2(GUI::MenuXpos + xPos, GUI::MenuYpos - 25), ImVec2(boxW, 25));
			g_GUI->RectFilled(HoverMouse ? g_backend->RedOrange : g_backend->ChillerRedOrange, ImVec2(GUI::MenuXpos + xPos, GUI::MenuYpos - 25), ImVec2(boxW, 25), false, 2.f);
		}
		else*/
			g_GUI->RectFilled(g_backend->ClearColour, ImVec2(GUI::MenuXpos * OptionCountforTopMenu, GUI::MenuYpos - 25), ImVec2(110, 25), false, 2.f);

		ImVec2 TextPos{ GUI::MenuXpos + xPos, GUI::MenuYpos - 25 };
		g_GUI->Text(Sub, g_backend->White, TextPos, m_font_big);
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
			float YPostion = (25.f * OptionCount - 20);
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

	void GUI::End(std::string sub)
	{
		Sub = sub;

		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		std::string time = std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
		float YPostion;
		OptionCount >= maxOption ? YPostion = 25.f * (maxOption + 1) : YPostion = 25.f * (OptionCount + 1) ;
		std::string Count = std::to_string(currentOption) + "/" + std::to_string(OptionCount);
		ImVec2 TextPos{ (GUI::MenuXpos + 10.f), YPostion + GUI::MenuYpos};
		g_GUI->Line(g_backend->White,  {GUI::MenuXpos, YPostion + GUI::MenuYpos - 5}, { GUI::MenuWidth , 0});
		g_GUI->Text(Count, g_backend->TextOnNomral, TextPos, NULL, true);
		g_GUI->Text("V: 1 | UI by Avi  | " + time + " | Cursor: off", g_backend->TextOnNomral, TextPos);

	}
	std::string optionInputString;
	int inputKeyDelay;
	bool GUI::setOptioninput(std::string text, std::string* output, int maxCharCount)
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
						else if (clicked.key == "ENTER")
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
						else if (optionInputString.length() < l_maxCharCount)
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
	bool openCliked, isclosed;
	bool openCliked2, isclosed2;

	void GUI::tick()
	{
		int MenuXpos = 10, MenuYpos = 130;

		ImGui::SetNextWindowPos(ImVec2(g_GUI->MenuXpos - 10, g_GUI->MenuYpos - 120));
		ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 25));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("Background", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus))
		{
			Titleblock();
			setOptionTop();
			BackGround();
	
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::End();
		control->controlTick();
		ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 25));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("Background2", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
		{

			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			setOption("Test", "test", "Test");
			End("Main Menu");
			if (isMenuOpen)
			{
				g_GUI->MenuXpos = ImGui::GetWindowPos().x + MenuXpos;
				g_GUI->MenuYpos = ImGui::GetWindowPos().y + MenuYpos;
			}
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::End();
		//ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 30));
		//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, .3));
		//ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		//if (ImGui::Begin("MenuWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
		//{
		//
		//}
		//ImGui::PopStyleVar();
		//ImGui::PopStyleColor();
		//ImGui::End();
		OptionCountforTopMenu = 0;
	}
	 
	void GUI::Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font, bool Right, bool center)
	{
		if (font == NULL)
			font = ImGui::GetDefaultFont();

		ImGui::PushFont(font);
		if (Right)
		{ 

			Pos.x = (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar(Text)).x
				- ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos.x);
		}
		else if (center)
		{
			float win_width = ImGui::GetWindowSize().x;
			float text_width = ImGui::CalcTextSize(Text.c_str()).x;
			Pos.x = ((win_width - text_width) * 0.5f) + Pos.x;
		}

		ImGui::GetCurrentWindow()->DrawList->AddText({ Pos.x , Pos.y }, ImGui::GetColorU32(Colour), Text.c_str());
		ImGui::PopFont();
	}
	ImVec2 GUI::add(ImVec2* vectorA, ImVec2* vectorB) {
		ImVec2 result;
		result.x = vectorA->x;
		result.y = vectorA->y;
		result.x += vectorB->x;
		result.y += vectorB->y;

		return result;
	}
	float getRightTextX(float Pos)
	{
		return (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar("Right")).x
			- ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos);
	}

	void GUI::RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled, float thik, float round)
	{
		ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
		const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));


		if (!Filled)
			ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour), round, 15, thik);
		else
			ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
				ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour));
	}

	void GUI::RectFilled(ImVec4 Colour, ImVec4 Colour2, ImVec4 Colour3, ImVec4 Colour4, ImVec2 Pos, ImVec2 Size, bool Filled)
	{
		ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
		const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));


		if (!Filled)
			ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour));
		else
			ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
				ImGui::GetColorU32(Colour2), ImGui::GetColorU32(Colour3), ImGui::GetColorU32(Colour4));
	}
	void GUI::Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness, bool Filled)
	{
		ImVec2 size = ImGui::CalcItemSize(ImVec2(rotation.x, rotation.y), 0.0f, 0.0f);
		const ImRect bb(ImVec2(Pos.x, Pos.y), add(&Pos, &size));

		ImGui::GetCurrentWindow()->DrawList->AddLine(bb.Max, bb.Min, ImGui::GetColorU32(Colour), Thinkness);
	}

}