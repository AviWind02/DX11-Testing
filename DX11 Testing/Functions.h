//
//extern int main();
//	class Input {
//	private:
//		std::string InputTick()
//		{
//			std::string StringReturn;
//		
//			ImGui::SetNextWindowPos(ImVec2(500, 220));
//			ImGui::SetNextWindowSize(ImVec2(270, 80));
//			ImGui::PushStyleColor(ImGuiCol_FrameBg, Ui->WhiteLowAlpha);
//			ImGui::PushStyleColor(ImGuiCol_WindowBg, Ui->BlackLowAlpha);
//			ImGui::PushStyleColor(ImGuiCol_Button, Ui->BlackLowAlpha);
//			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);
//			if (ImGui::Begin("TextWindow", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
//			{
//
//				static char Text[2255] = "";
//				ImGui::Text("Enter value");
//				ImGui::InputText("", Text, IM_ARRAYSIZE(Text));
//				if (ImGui::Button("Ok", ImVec2(50, 20)))
//				{
//					StringReturn = Text;
//					InputWindowInUse = false;
//				}
//				ImGui::SameLine();
//				if (ImGui::Button("Cancel", ImVec2(50, 20)))
//				{
//					StringReturn = "Cancel";
//					InputWindowInUse = false;
//				}
//			}
//			ImGui::PopStyleVar();
//			ImGui::PopStyleColor();
//			ImGui::PopStyleColor();
//			ImGui::PopStyleColor();
//			ImGui::End();
//			return StringReturn;
//		}
//	public:
//
//		bool InputWindowInUse;
//		void Tick()
//		{
//			InputTick();
//		}
//		std::string TextInput()
//		{
//			InputWindowInUse = true;
//			return InputTick();
//		}
//		
//	};
//	extern Input* input = new Input();
//
