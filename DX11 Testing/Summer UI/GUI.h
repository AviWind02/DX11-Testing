#pragma once

namespace summer
{
	class GUI
	{
	public:

		static float MenuWidth, MenuHight, MenuXpos, MenuYpos;
		void tick();
		bool setOption(std::string text, std::string Rtext, std::string DEC = "");
		bool setOptioninput(std::string text, std::string* output, int maxCharCount = 15);
		void End(std::string sub);
		void Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness = 1.f, bool Filled = false);
		void Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font = nullptr, bool Right = false, bool center = false);
		void RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled = true, float thik = 1.f, float round = 0.f);
		void RectFilled(ImVec4 Colour, ImVec4 Colour2, ImVec4 Colour3, ImVec4 Colour4, ImVec2 Pos, ImVec2 Size, bool Filled = true);
		ImVec2 add(ImVec2* vectorA, ImVec2* vectorB);
	};
	extern GUI* g_GUI;
}
