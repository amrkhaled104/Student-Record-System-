#include "include.h"

u32 main()
{
	clearScreen();
	load_data();
	system_init();
	save_data();
}

void system_init()
{
	u8 i=0;
	while(1)
	{
		u32 Logout;
		if(i++!=0)
		{
			
		
		   while(1)
		   {
			
			    printf("\n\n                                      If You Want Continue Enter Any Number Except 0\n ");
			    ES current_error_state=take_number(&Logout);
		        Error(current_error_state);
			    if(current_error_state==valid) break;
		    }
		  	if(Logout==0)
		    {
		      	Logout=1;
				clearScreen();
				printf("                            Bya Bya Htw7shniiiiiiiiii ");
			    break;
		    } 
		    else
		    {
			    Logout=0;
		    }
		  
		}
	

		u32 choice=0,i=0;
		if(choice==1||choice==2||i==0){
			//decoration

		printf("\n\n"
		"\n\t\t\t        *********************************************"
		"\n\t\t\t        =                  WELCOME                  ="
		"\n\t\t\t        =                    TO                     ="
		"\n\t\t\t        =                 Om Ahmed                  ="
		"\n\t\t\t        =               Student Record              ="
		"\n\t\t\t        =                 MANAGEMENT                ="
		"\n\t\t\t        =                   SYSTEM                  ="
		"\n\t\t\t        *********************************************"
		"\n\n");

		i++;
		}
		while(1)
		{
					//admin or user
			printf("                     1-->Admin                                                  2-->User\n\n");
			ES current_error_state=take_number(&choice);
			Error(current_error_state);
			if(current_error_state==valid) break;
		}
		clearScreen();
		switch(choice)
		{
			case 1:
			//check
			/*
			Here, after I found out that the user is an admin and not a normal user,4
			I ask him for some information and based on it I will see if it is true or not.
			*/
			      if(login(choice)==valid)
				  {
					  /*Here, I looked at a function called login. I can see if he is actually an admin. Is this information that
					  he entered correct or not? If someone like this came back to me, I would know that he is really an admin. Based on
					  it, some permissions will be opened for him.*/
					  Admin_choice();
				  }
			break;

			case 2:
					if(login(choice)==valid)
					{
						user_choice();
					}
			break;

		}
		if(Logout) break;
    }

}
