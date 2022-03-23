#include "IncludeFiles.h"
float Blue::MenuWidth = 400, Blue::MenuHight = 500, Blue::MenuXpos = 100, Blue::MenuYpos = 120;
Blue* blueUI = new Blue();


void Titleblock()
{

	Blues_UI->RectFilled(Blues_UI->LowGrey, Blues_UI->BlackLowAlpha, Blues_UI->LowGrey, Blues_UI->BlackLowAlpha, { Blue::MenuXpos, Blue::MenuYpos - 80 }, { Blue::MenuWidth, 80 });//back colours
	Blues_UI->RectFilled(Blues_UI->BlackLowAlpha, Blues_UI->BlackLowAlpha, Blues_UI->BlackLowAlpha, Blues_UI->LighterBlue, { Blue::MenuXpos, Blue::MenuYpos - 80 }, { Blue::MenuWidth, 80 });//shade
	Blues_UI->RectFilled(Blues_UI->LowGrey, { Blue::MenuXpos,   Blue::MenuYpos - 80 }, { Blue::MenuWidth, 80 });//grey
	Blues_UI->RectFilled(Blues_UI->LowGrey, { Blue::MenuXpos,   Blue::MenuYpos - 80 }, { Blue::MenuWidth, 80 });//grey
	Blues_UI->RectFilled(Blues_UI->LowGrey, { Blue::MenuXpos,   Blue::MenuYpos - 80 }, { Blue::MenuWidth, 80 });//grey
	//Loadimage("Title", "C:\\Users\\gilla\\Desktop\\Logo.png", { MenuXpos - 11,  MenuYpos - 96 }, { (float)MenuWidth, 890 }, { (float)MenuWidth, 90 });
	Blues_UI->RectFilled(Blues_UI->ScrollBar, { Blue::MenuXpos,   Blue::MenuYpos - 80 }, { Blue::MenuWidth, 80 }, false, 2.f);//Line Around
}
void BackGround()
{
	float Y;
	if (OptionCountForBackGround < maxOption) Y = (float)((OptionCountForBackGround + 1) * 25); else Y = (maxOption + 1) * 25;
	Blues_UI->RectFilled(Blues_UI->BlackLowAlpha, Blues_UI->LowGrey, Blues_UI->BlackLowAlpha, Blues_UI->LowGrey, { Blue::MenuXpos, Blue::MenuYpos }, { Blue::MenuWidth, Y });//back colours
	Blues_UI->RectFilled(Blues_UI->BlackLowAlpha, Blues_UI->BlackLowAlpha, Blues_UI->BlackLowAlpha, Blues_UI->LighterBlue, { Blue::MenuXpos, Blue::MenuYpos }, { Blue::MenuWidth, Y });//shade
	Blues_UI->RectFilled(Blues_UI->LowGrey, { Blue::MenuXpos,  Blue::MenuYpos }, { Blue::MenuWidth, Y });//grey
	Blues_UI->RectFilled(Blues_UI->LowGrey, { Blue::MenuXpos,  Blue::MenuYpos }, { Blue::MenuWidth, Y });//grey
	Blues_UI->RectFilled(Blues_UI->LowGrey, { Blue::MenuXpos,  Blue::MenuYpos }, { Blue::MenuWidth, Y });//grey
	Blues_UI->RectFilled(Blues_UI->ScrollBar, { Blue::MenuXpos,  Blue::MenuYpos }, { Blue::MenuWidth, Y }, false, 2.f);//Line Around
}


void setOptionText(ImVec2 TextPos, bool Hover, std::string text, std::string Rtext = "", ImVec4 colour1 = Blues_UI->TextOnHover, ImVec4 colour2 = Blues_UI->TextOnNomral)
{
	if (control->isMenuOpen)
	{
		Blues_UI->RectFilled(Hover ? Blues_UI->ScrollBar : Blues_UI->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(Blue::MenuWidth, 20), false);
		Blues_UI->RectFilled(Hover ? Blues_UI->Grey : Blues_UI->ClearColour, ImVec2(TextPos.x, TextPos.y), ImVec2(Blue::MenuWidth, 20));
		Blues_UI->Text(text, Hover ? colour1 : colour2, { TextPos.x + 10.f, TextPos.y + 2.5f });
		Blues_UI->Text(Rtext, Hover ? colour1 : colour2, { TextPos.x + 5.f, TextPos.y + 2.5f }, NULL, true);
		//SideLineRGB(Ui->currentOption * 25.f);
	}
}



bool setOption(std::string text, std::string Rtext, std::string DEC = "")
{

	OptionCount++;
	OptionCountForBackGround++;
	bool HoverMouse, Held;
	bool Hover = currentOption == OptionCount ? true : false;
	bool pressed = control->MouseClickOption(text, &HoverMouse, &Held);
	if (currentOption <= maxOption && OptionCount <= maxOption)
	{

		float YPostion = 25.f * OptionCount - 20;
		ImVec2 TextPos{ Blue::MenuXpos, YPostion + Blue::MenuYpos };
		setOptionText(TextPos, (HoverMouse || Hover), text, Rtext);
	}
	else if (OptionCount > (currentOption - maxOption) && OptionCount <= currentOption)
	{
		float YPostion = 25.f * ((OptionCount - 1) - (currentOption - maxOption));
		ImVec2 TextPos{ Blue::MenuXpos, YPostion + Blue::MenuYpos };
		setOptionText(TextPos, (HoverMouse || Hover), text, Rtext);

	}
	if ((pressed && HoverMouse) || (control->SelectPressed && Hover))
		return true;
	return false;
}
void End(std::string SubTitle)
{
	if (control->isMenuOpen)
	{
		float YPostion;
		OptionCount >= 16 ? YPostion = 25.f * 16 : YPostion = 25.f * (OptionCount);
		std::string Count = "[" + std::to_string(currentOption) + "/" + std::to_string(OptionCount) + "]";
		ImVec2 TextPos{ (Blue::MenuXpos + 10.f), YPostion + Blue::MenuYpos + 5 };
		Blues_UI->Text(Count, Blues_UI->TextOnNomral, TextPos , NULL, true);
		Blues_UI->Text("V1 | " + SubTitle, Blues_UI->TextOnNomral, TextPos);
	}
}

void allMenuStuff();
void Blue::tick()
{



	 
	ImGui::SetNextWindowPos(ImVec2(Blue::MenuXpos - 10, Blue::MenuYpos - 90));
	ImGui::SetNextWindowSize(ImVec2(Blue::MenuWidth + 15, Blue::MenuHight + 20));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
	if (ImGui::Begin("Background", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoInputs))
	{
		Titleblock();
		BackGround();
	}
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::End();
	control->controlTick();
	ImGui::SetNextWindowSize(ImVec2(Blue::MenuWidth + 15, Blue::MenuHight + 25));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
	if (ImGui::Begin("MenuWindow", 0 , ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
	{
		allMenuStuff();
		Blue::MenuXpos = ImGui::GetWindowPos().x;
		Blue::MenuYpos = ImGui::GetWindowPos().y;
	}
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::End();


}


void allMenuStuff()
{
	for (int i = 0; i < 40; i++)
		if (setOption("Test " + std::to_string(i), ">", "fff"))
			std::cout << i << std::endl;
	End("Main Menu");
}