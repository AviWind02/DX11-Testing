#pragma once
#include"Simple UI.h"
namespace Simple_UI
{
	class Menu {
	private:

	public:
		void Tick()
		{
			Ui->control();
			ImGui::SetNextWindowPos(ImVec2(-3.9f, 0));
			ImGui::SetNextWindowSize(ImVec2(600, 1080));
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
			if (ImGui::Begin("MenuWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
			{
				UI->Backpart();
				UI->TestOption10();

			}
			ImGui::PopStyleVar();
			ImGui::PopStyleColor();
			ImGui::End();
		}
	};
	extern Menu* SimpleMenu = new Menu();

}