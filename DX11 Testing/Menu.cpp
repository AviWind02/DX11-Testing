#include "IncludeFiles.h"


/*
UP/NUM UP
DOWN/NUM DOWN
RIGHT/NUM RIGHT
LEFT/NUM LEFT

MOUSE DRAG
MOUSE CLICK
HOLD CTRL to lock mouse function to edit int or float
C is used to edit a int or float

To drag menu, drag by hold the under the bottom of the menu
*/

int test; 
float tests;
void Main()
{
	switch (OnSubMenu)
	{
		case MainMenu:
		{
			SubOption("MainMenu", TestMenu);
			SubOption("MainMenu2", TestMenu);
			SubOption("MainMenu3", TestMenu);
			SubOption("MainMenu4", TestMenu);
			End("Main Menu");

		}
		break;
		case TestMenu:
		{
			for (int i = 0; i < 24; i++)
				if (Option("Test" + std::to_string(i)))
					std::cout << i << std::endl;
			Int("Int", test, 0, 100);
			Float("Float", tests, .5f, 100.f);
			End("Main Menu");
		}
		break;
	}
		
	
}