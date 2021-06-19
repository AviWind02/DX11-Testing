#pragma once
namespace Normal_UI
{
	class Menu {
	private:

	public:
		void Tick()
		{
			UI->control();
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImVec2(400, 520));
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
			if (ImGui::Begin("MenuWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
			{
				UI->Title("MainMenu");
				for (int i = 0; i < 22; i++)
					if (UI->Option("Nomral Option"))
						std::cout << i;
				UI->End();
			}
			ImGui::PopStyleVar();
			ImGui::PopStyleColor();
			ImGui::End();
		}
	};
	extern Menu* NormalMenu = new Menu();

}