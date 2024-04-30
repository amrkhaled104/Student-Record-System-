#include "include.h"

u32 main()
{
	clearScreen();
	if(welcome_admin()==1) goto a;
	load_data();
	system_init();
	save_data();
	a:return 0;
}

