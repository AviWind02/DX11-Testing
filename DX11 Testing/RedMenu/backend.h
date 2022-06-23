#pragma once
inline char* StringToChar(std::string string); // Handy little thing

namespace redMenu
{
	extern bool isMenuOpen;
	class backend
	{

	public:
		void Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness = 1.f, bool Filled = false);
		void Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font = nullptr, bool Right = false);
		void RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled = true, float thik = 1.f, float round = 0.f);
		void RectFilled(ImVec4 Colour, ImVec4 Colour2, ImVec4 Colour3, ImVec4 Colour4, ImVec2 Pos, ImVec2 Size, bool Filled = true);
		std::string getKeyCliked();

		char* StringToChar(std::string string);
		ImVec2 add(ImVec2* vectorA, ImVec2* vectorB);
		float getRightTextX(float Pos);

		enum SubMenu {
			MainMenu_Local,/*All local options start fromhere*/
			MainMenu_Online,/*All Online options start from here*/
			MainMenu_Protection,/*All Protection options start from here*/

		}; SubMenu OnSubMenu = MainMenu_Local;

		enum Main_SubMenu {
			Main_Local,
			Main_Online,
			Main_Protection
		}; Main_SubMenu Main_OnSubMenu = Main_Protection;

		void BackSubmenu();
		void NextSubmenu(backend::SubMenu Menu);



		static ImVec4 MiddleBoxBack;
		static ImVec4 ScrollBar;
		static ImVec4 TextOnNomral;
		static ImVec4 TextOnHover;
		static ImVec4 Titlebox;
		static ImVec4 TextInTitleBox;
		static ImVec4 BottomEndBox;
		static ImVec4 BottomTextCount;


		const ImVec4 WatermelonRed = ImColor(251, 5, 56, 255);
		const ImVec4 WatermelonPick = ImColor(251, 8, 89, 255);
		const ImVec4 MelonWhite = ImColor(242, 194, 169, 255);
		const ImVec4 MelonWhiteLowAlpha = ImColor(242, 194, 169, 155);
		const ImVec4 MelonSeedBrown = ImColor(73, 49, 9, 255);
		const ImVec4 MelonOrange = ImColor(243, 87, 43, 255);
		const ImVec4 RedColour = ImColor(245, 2, 2, 255);
		const ImVec4 RedColourLighter = ImColor(161, 2, 2, 255);
		const ImVec4 White = ImColor(255, 255, 255, 255);
		const ImVec4 WhiteLowAlpha = ImColor(255, 255, 255, 100);
		const ImVec4 HotPink = ImColor(255, 105, 180, 255);
		const ImVec4 Black = ImColor(0, 0, 0, 255);

		const ImVec4 RedOrange = ImColor(255, 100, 73, 255);
		const ImVec4 ChillerRedOrange = ImColor(254, 101, 0);
		const ImVec4 TitleBlockLavaOrange = ImColor(209, 75, 1);

		const ImVec4 BlackLowAlpha = ImColor(0, 0, 0, 100);
		const ImVec4 ClearColour = ImColor(0, 0, 0, 0);
		const ImVec4 Orange = ImColor(249, 87, 0, 255);
		const ImVec4 BlueColour = ImColor(0, 164, 204, 255);
		const ImVec4 LightBlue = ImColor(0, 140, 255, 255);
		const ImVec4 LighterBlue = ImColor(152, 212, 252, 255);
		const ImVec4 OrangeLowAlpha = ImColor(0, 164, 204, 155);
		const ImVec4 BrownSugar = ImColor(160, 120, 85, 255);
		const ImVec4 Beige = ImColor(212, 185, 150, 155);
		const ImVec4 BrownSugarAlpha = ImColor(160, 120, 85, 155);
		const ImVec4 CherryTomato = ImColor(233, 75, 60, 255);
		const ImVec4 PANTONEBlackC = ImColor(45, 41, 38, 255);
		const ImVec4 PANTONEBlackCLowAlpha = ImColor(160, 120, 85, 155);
		const ImVec4 SeaFoam = ImColor(112, 235, 204, 255);
		const ImVec4 DeepAqua = ImColor(0, 59, 70, 255);
		const ImVec4 wave = ImColor(102, 165, 173, 255);
		const ImVec4 DeepAqualowAplha = ImColor(0, 59, 70, 155);
		const ImVec4 BabyBlue = ImColor(137, 207, 240, 255);
		const ImVec4 AcidGreen = ImColor(176, 191, 26, 255);
		const ImVec4 AcidGreenlowAlpha = ImColor(176, 191, 26, 155);
		const ImVec4 DrakPurple = ImColor(133, 22, 233);
		const ImVec4 DrakLimeGreen = ImColor(122, 233, 22);
		const ImVec4 DrakPurpleLowAlpha = ImColor(133, 22, 233, 155);
		const ImVec4 Grey = ImColor(0, 0, 0, 175);
		const ImVec4 LowGrey = ImColor(0, 0, 0, 55);


	};
	extern backend* g_backend;

	struct getKey { int numericvalue; std::string key; };

	extern  std::vector<getKey> g_getKeys;



}
