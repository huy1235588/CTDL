#include "menu.hpp"
#include <conio.h>

int main()
{

	while (true)
	{
		Menu();
		int chon = ChonMenu();
		XuLyMenu(chon);
	}

	return 0;
}