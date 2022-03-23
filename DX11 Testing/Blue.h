#pragma once
class Blue
{
public:
	static float MenuWidth, MenuHight, MenuXpos, MenuYpos;
	void tick();
	bool setOption(std::string text, std::string Rtext, std::string DEC = "");
	void End(std::string SubTitle);


};

extern Blue* blueUI;