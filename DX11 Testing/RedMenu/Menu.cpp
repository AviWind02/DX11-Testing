#include"../IncludeFiles.h"
#include "backend.h"


namespace redMenu {
	void Menu()
	{
		switch (g_backend->Main_OnSubMenu)
		{
		case g_backend->Main_Local:
		{
			switch (g_backend->OnSubMenu)
			{
			case g_backend->MainMenu_Local:
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");

			break;








			}
		}
		break;
		case g_backend->Main_Online:
		{
			switch (g_backend->OnSubMenu)
			{
			case g_backend->MainMenu_Online:
				Option("this is Online menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");

			break;









			}
		}
		break;
		case g_backend->Main_Protection:
		{
			switch (g_backend->OnSubMenu)
			{
			case g_backend->MainMenu_Protection:
				Option("this is protection menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");

			break;









			}
		}
		break;
		}
	}
}