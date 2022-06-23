#include "IncludeFiles.h"
#include "RedMenu/UI.h"
#include "RedMenu/backend.h"
#pragma warning(disable : 4996).

using namespace redMenu;
int optionKeyPressGrab;

std::string RoundFloat(float Float, const char* format = "%.4g")
{
	char NameBuffer[50];
	sprintf(NameBuffer, format, Float);
	return (std::string)NameBuffer;
}
bool Option(std::string option, std::string description)
{
	return g_GUI->setOption(option, "", description);
}
bool Option(std::string option, std::string rightText, std::string description)
{
	return g_GUI->setOption(option, rightText, description);
}
bool Toggle(std::string text, bool* toggle, std::string description)
{
	std::string Toggle = *toggle ? "[-]" : "[O]";
	if (g_GUI->setOption(text, Toggle, description))
	{
		*toggle ^= 1;
		return true;
	}
	return false;
}
bool SubMenu(std::string text, backend::SubMenu SubMenu, std::string description)
{
	if (g_GUI->setOption(text, ">", description))
	{
		g_backend->NextSubmenu(SubMenu);
		return true;
	}
	return false;
}
bool Int(std::string text, int& Main, int min, int max, int step, std::string description, bool returnOnSideClick, int delay)
{
	if (delay == NULL)
		delay = 150;

	bool Held;
	std::string NumberMain = std::to_string(Main);
	std::string NumberMax = std::to_string(max);
	std::string NumberCombo = NumberMain + "/" + NumberMax;
	std::string ShowNumber = "[" + NumberCombo + "]";
	if (g_GUI->setOption(text, ShowNumber, description))
		return true;


	if (currentOption == OptionCount)
	{
		if (GetTickCount64() - optionKeyPressGrab > delay)
		{
			if (RightKey())
			{
				if (Main < max)
					Main += step;
				else
					Main = min;
				optionKeyPressGrab = GetTickCount64();
				if (returnOnSideClick)
					return true;
			}
			else if (LeftKey())
			{
				if (Main >= min)
					Main -= step;
				else
					Main = max;
				optionKeyPressGrab = GetTickCount64();
				if (returnOnSideClick)
					return true;
			}
		}
	}
	return false;
}

bool Float(std::string text, float& Main, float min, float max, float step, std::string description, bool returnOnSideClick, int delay)
{
	if (delay == NULL)
		delay = 150;
	if (delay == 1)
		delay = 0;
	bool Held;
	std::string NumberMain = RoundFloat(Main);
	std::string NumberMax = RoundFloat(max);
	std::string NumberCombo = NumberMain + "/" + NumberMax;
	std::string ShowNumber = "[" + NumberCombo + "]";
	if (g_GUI->setOption(text, ShowNumber, description))
		return true;
	if (currentOption == OptionCount)
	{
		if (GetTickCount64() - optionKeyPressGrab > delay)
		{
			if (RightKey())
			{
				if (Main < max)
					Main += step;
				else
					Main = min;
				optionKeyPressGrab = GetTickCount64();
				if (returnOnSideClick)
					return true;
			}
			else if (LeftKey())
			{
				if (Main >= min)
					Main -= step;
				else
					Main = max;
				optionKeyPressGrab = GetTickCount64();
				if (returnOnSideClick)
					return true;
			}
		}
	}
	return false;

}

bool StringArray(std::string text, std::vector<std::string> Main, int& intg, bool* toggle, std::string description, int delay)
{
	if (delay == NULL)
		delay = 150;

	bool Held;

	std::string Toggle = *toggle ? "[-]" : "[O]";
	std::string ShowArray = "[" + Main[intg] + "] " + Toggle;
	if (g_GUI->setOption(text, ShowArray, description)) {
		*toggle ^= 1;
		return true;
	}

	if (currentOption == OptionCount)
	{
		if (GetTickCount64() - optionKeyPressGrab > delay)
		{
			if (RightKey())
			{
				if (intg < Main.size() - 1)
					intg += 1;
				else
					intg = 0;
				optionKeyPressGrab = GetTickCount64();
			}
			else if (LeftKey())
			{
				if (intg >= 1)
					intg -= 1;
				else
					intg = Main.size() - 1;
				optionKeyPressGrab = GetTickCount64();
			}
		}
	}
	return false;
}
bool StringArray(std::string text, std::vector<std::string> Main, int& intg, std::string description, int delay)
{
	if (delay == NULL)
		delay = 150;

	bool Held;
	int max = Main.size();
	int min = 0;
	std::string ShowArray = "[" + Main[intg] + "]";
	if (g_GUI->setOption(text, ShowArray, description)) 
		return true;


	if (currentOption == OptionCount)
	{
		if (GetTickCount64() - optionKeyPressGrab > delay)
		{
			if (RightKey())
			{
				if (intg < Main.size() - 1)
					intg += 1;
				else
					intg = 0;
				optionKeyPressGrab = GetTickCount64();
			}
			else if (LeftKey())
			{
				if (intg >= 1)
					intg -= 1;
				else
					intg = Main.size() - 1;
				optionKeyPressGrab = GetTickCount64();
			}
		}
	}

	return false;
}
bool OptionKeyInput(std::string option, std::string* ouput, int maxChar)
{
	return g_GUI->setOptioninput(option, ouput, maxChar);
}
void End(std::string SubTitle)
{
	if (isMenuOpen)
	{
		g_GUI->End(SubTitle);
	}
}