#include"../IncludeFiles.h"
#include "backend.h"


namespace redMenu {
	std::string tets;
	void Menu()
	{
		switch (g_backend->Main_OnSubMenu)
		{
		case g_backend->Main_Local:
		{
			switch (g_backend->OnSubMenu)
			{
			case g_backend->MainMenu_Local:
				Option("this is local menu", "Danny is gay");
				OptionKeyInput("Input:", &tets);
				Option(tets, tets);
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu");
				Option("this is local menu", "Viverra adipiscing at in tellus. Blandit aliquam etiam erat velit scelerisque. Cursus euismod quis viverra nibh. Tempor nec feugiat nisl pretium fusce id velit ut. Etiam erat velit scelerisque in dictum non consectetur. Feugiat pretium nibh ipsum consequat nisl vel pretium lectus. Gravida in fermentum et sollicitudin ac orci phasellus egestas. Iaculis nunc sed augue lacus viverra vitae.Sollicitudin aliquam ultrices sagittis orci a.Morbi blandit cursus risus at ultrices mi.Eu lobortis elementum nibh tellus molestie nunc non.Viverra tellus in hac habitasse platea dictumst vestibulum rhoncus.Tellus cras adipiscing enim eu turpis egestas.Metus aliquam eleifend mi in nulla posuere sollicitudin aliquam.Diam vulputate ut pharetra sit amet aliquam id diam.Erat velit scelerisque in dictum non consectetur.");
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