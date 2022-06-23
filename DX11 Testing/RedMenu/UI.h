#pragma once

namespace redMenu
{
	class GUI
	{
	public:
		
		static float MenuWidth, MenuHight, MenuXpos, MenuYpos;
		void tick();
		bool setOption(std::string text, std::string Rtext, std::string DEC = "");
		bool setOptioninput(std::string text, std::string* output, int maxCharCount = 15);
		void End(std::string SubTitle);

	};
	extern GUI* g_GUI;
}
