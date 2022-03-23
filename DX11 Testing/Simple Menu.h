//#pragma once
//#include "Simple UI.h"
//extern void Loadimage(const char* FilePath, ImVec2 Pos);
//
//namespace Simple_UI
//{
//	class Menu {
//	private:
//	public:
//		void Tick()
//		{
//			Ui->control();
//			ImGui::SetNextWindowPos(ImVec2(50, 10));
//			ImGui::SetNextWindowSize(ImVec2(UI->getMenuWidth() + 150, 560));
//			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
//			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
//			if (ImGui::Begin("MenuWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
//			{
//				UI->tick();
//			}
//			ImGui::PopStyleVar();
//			ImGui::PopStyleColor();
//			ImGui::End();
//
//
//		}
//
//	};
//	extern Menu* SimpleMenu = new Menu();
//
//}