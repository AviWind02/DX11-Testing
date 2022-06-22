#pragma once
#include "../IncludeFiles.h"
#include "backend.h"
#include "UI.h"
#include "Menu.h"
extern void Loadimage(const char* ID, const char* FilePath, ImVec2 Pos, ImVec2 Size);
namespace redMenu
{
	float GUI::MenuWidth = 360, GUI::MenuHight = 500, GUI::MenuXpos = 100, GUI::MenuYpos = 120;
	GUI* g_GUI = new GUI();


	void Titleblock()
	{
		if (isMenuOpen)
		{
			//g_backend->RectFilled(g_backend->LowGrey, g_backend->BlackLowAlpha, g_backend->LowGrey, g_backend->BlackLowAlpha, { GUI::MenuXpos, GUI::MenuYpos - 80 }, { GUI::MenuWidth, 80 });//back colours
			//g_backend->RectFilled(g_backend->BlackLowAlpha, g_backend->BlackLowAlpha, g_backend->BlackLowAlpha, g_backend->RedColourLighter, { GUI::MenuXpos, GUI::MenuYpos - 80 }, { GUI::MenuWidth, 80 });//shade
			//g_backend->RectFilled(g_backend->LowGrey, { GUI::MenuXpos,   GUI::MenuYpos - 80 }, { GUI::MenuWidth, 80 });
			//g_backend->RectFilled(g_backend->RedColourLighter, { GUI::MenuXpos,   GUI::MenuYpos - 80 }, { GUI::MenuWidth, 80 }, false, 2.f);//Line Around
			Loadimage("Title", "C:\\Users\\gilla\\Desktop\\ETERNITY-HEADER-DONE_1.jpg", { GUI::MenuXpos - 10,  GUI::MenuYpos - 80 }, { (float)GUI::MenuWidth + 15, 80 });

			g_backend->RectFilled(g_backend->Black, ImVec2(GUI::MenuXpos, GUI::MenuYpos - 27), ImVec2(GUI::MenuWidth, 25));
			g_backend->RectFilled(g_backend->Black, { GUI::MenuXpos,   GUI::MenuYpos - 27 }, { GUI::MenuWidth, 25 }, false, 2.f);//Line Around

		}
	}
	void BackGround()
	{
		if (isMenuOpen)
		{
			float Y;
			if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround + 1) * 25); else Y = (maxOption + 1) * 25;
			g_backend->RectFilled(g_backend->BlackLowAlpha, g_backend->ChillerRedOrange, g_backend->ChillerRedOrange, g_backend->LowGrey, { GUI::MenuXpos, GUI::MenuYpos }, { GUI::MenuWidth, Y });//back colours
			g_backend->RectFilled(g_backend->BlackLowAlpha, g_backend->LowGrey, g_backend->BlackLowAlpha, g_backend->LowGrey, { GUI::MenuXpos, GUI::MenuYpos }, { GUI::MenuWidth, Y });//back coloursExtra
			g_backend->RectFilled(g_backend->LowGrey, { GUI::MenuXpos,  GUI::MenuYpos }, { GUI::MenuWidth, Y });//grey
			g_backend->RectFilled(g_backend->ChillerRedOrange, { GUI::MenuXpos,  GUI::MenuYpos }, { GUI::MenuWidth, Y }, false, 2.f);//Line Around

		}
	}


	void setOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = g_backend->TextOnHover, ImVec4 colour2 = g_backend->TextOnNomral)
	{

		//g_backend->RectFilled(Hover ? g_backend->ScrollBar : g_backend->ClearColour, ImVec2(TextPos.x - 25, TextPos.y + 5), ImVec2(GUI::MenuWidth, 20), false);
		g_backend->RectFilled(Hover ? g_backend->Grey : g_backend->ClearColour, ImVec2(TextPos.x - 8, TextPos.y + 2.f), ImVec2(GUI::MenuWidth + 2, 20));
		g_backend->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y + 2.5f });
		g_backend->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 5.f, TextPos.y + 2.5f }, NULL, false);
		//SideLineRGB(Ui->currentOption * 25.f);

	}

	//OptionCountforTopMenumaxOptionforTop
	bool setOptionTop(std::string text)
	{
		float boxW = 135;
		OptionCountforTopMenu++;
		bool HoverMouse, Held;
		bool Hover = currentOptionforTopMenu == OptionCountforTopMenu ? true : false;
		bool pressed = control->MouseClick(StringToChar(text), ImVec2(GUI::MenuXpos * OptionCountforTopMenu, GUI::MenuYpos - 25), ImVec2(boxW, 25), &HoverMouse, &Held);
		if (Hover || HoverMouse)
		{
			if (pressed)
				currentOptionforTopMenu = OptionCountforTopMenu;
			g_backend->RectFilled(HoverMouse ? g_backend->RedOrange : g_backend->ChillerRedOrange, ImVec2(GUI::MenuXpos * OptionCountforTopMenu, GUI::MenuYpos - 25), ImVec2(boxW, 25));
			g_backend->RectFilled(HoverMouse ? g_backend->RedOrange : g_backend->ChillerRedOrange, ImVec2(GUI::MenuXpos * OptionCountforTopMenu, GUI::MenuYpos - 25), ImVec2(boxW, 25), false, 2.f);
		}
		else
			g_backend->RectFilled(g_backend->ClearColour, ImVec2(GUI::MenuXpos * OptionCountforTopMenu, GUI::MenuYpos - 25), ImVec2(110, 25), false, 2.f);
		ImVec2 TextPos{ (GUI::MenuXpos* OptionCountforTopMenu + 25), GUI::MenuYpos - 25 };
		g_backend->Text(text, g_backend->White, TextPos, m_font_big);
		return 0;
	}

	bool GUI::setOption(std::string text, std::string Rtext, std::string DEC)
	{

		OptionCount++;
		OptionCountForBackGround++;
		bool HoverMouse, Held;
		bool Hover = currentOption == OptionCount ? true : false;
		bool pressed = control->MouseClickOption(text, &HoverMouse, &Held);
		if (HoverMouse)
			currentOption = OptionCount;
		if (currentOption <= maxOption && OptionCount <= maxOption)
		{

			float YPostion = 25.f * OptionCount - 20;
			ImVec2 TextPos{ GUI::MenuXpos , YPostion + GUI::MenuYpos };
			setOptionText(TextPos, (HoverMouse || Hover), text, Rtext);
		}
		else if (OptionCount > (currentOption - maxOption) && OptionCount <= currentOption)
		{
			float YPostion = 25.f * ((OptionCount - 1) - (currentOption - maxOption));
			ImVec2 TextPos{ GUI::MenuXpos, YPostion + GUI::MenuYpos };
			setOptionText(TextPos, (HoverMouse || Hover), text, Rtext);

		}
		if ((pressed && HoverMouse) || (control->SelectPressed && Hover))
			return true;
		return false;
	}
	void GUI::End(std::string SubTitle)
	{

		float YPostion;
		OptionCount >= 16 ? YPostion = 25.f * 16 : YPostion = 25.f * (OptionCount);
		std::string Count = "[" + std::to_string(currentOption) + "/" + std::to_string(OptionCount) + "]";
		ImVec2 TextPos{ (GUI::MenuXpos + 10.f), YPostion + GUI::MenuYpos + 5 };
		g_backend->Text(Count, g_backend->TextOnNomral, TextPos, NULL, true);
		g_backend->Text("Version: Red | " + SubTitle, g_backend->TextOnNomral, TextPos);

	}
	void GUI::tick()
	{
		ImGui::SetNextWindowPos(ImVec2(g_GUI->MenuXpos - 10, g_GUI->MenuYpos - 90));
		ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 20));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("Background", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus))
		{
			Titleblock();
			setOptionTop("Local");
			setOptionTop("Online");
			setOptionTop("Protection");
			BackGround();
		}
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::End();
		control->controlTick();
		ImGui::SetNextWindowSize(ImVec2(g_GUI->MenuWidth + 15, g_GUI->MenuHight + 25));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
		if (ImGui::Begin("MenuWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize ))
		{
			if (isMenuOpen)
			{
	
				setOption("Hey", "", "");
				setOption("Hey67", "", "");
				setOption("Hey867", "", "");
				setOption("Hey687", "", "");
				setOption("Hey4352", "", "");
				setOption("Hey654", "", "");
				setOption("Hey12", "", "");
				setOption("Hey98", "", "");
				setOption("Hey657", "", "");
				setOption("Hey5324", "", "");
				setOption("Hey33", "", "");
				End("Main Menu");
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