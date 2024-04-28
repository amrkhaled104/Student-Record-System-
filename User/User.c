#include "include.h"
extern struct STUDENTS * Head;
struct STUDENTS* ptrfind=NULL;
u32 User_Id;
void user_choice()
{
	while(1)
	{
        //after checking the user's id,we give him options about what he want to do in his acount
		printf("                       1-->View your record                       2-->Edit your record\n\n");
        u32 choice;
        scanf("%d",&choice);
		printf("                       Enter Id:");
		scanf("%d",&User_Id);
		//this function to reach student record by his ID and the pointer will be there. when he enters the operation, it will be done directly
		if(Find_Student()==0)
            break;
	    switch(choice)
        {
            case 1:
                //function to view user's data
                view_your_record();
            break;
            case 2:
                //function to edit user's profile
			    Edit();
            break;
            default:
            printf("                       Wrong number , Try again\n\n");
            break;
        }
	    printf("\n                 Do You Want Back To Main choice`s If you want Enter 1 and If Not Enter 0\n\n");
	    u8 dession;
	    scanf("%d",&dession);
		clearScreen();
	    if (dession!=1)
            break;
   }
}
u32 Find_Student()
{
	u32 found =0 ;
	ptrfind=Head;
	while(ptrfind!=NULL)
	{
	  if(ptrfind->Id==User_Id)
	  {
		  found =1 ;
		  break;
	  }
	  	ptrfind= ptrfind->NEXT ;
	}
	if (!found)
	{

	     printf("                                                              Student with ID %d not found.\n\n", User_Id);
		 return 0;
	}
}
void view_your_record()
{

    printf("                       ------------------%s INFO------------------\n\n",ptrfind->Name);
    printf("                       Name: %s\n                       Grade: %d\n                       ID: %d\n                       Gender: %s\n                       Password: %s\n", ptrfind->Name, ptrfind->Grade,ptrfind->Id, ptrfind->Gender, ptrfind->Password);
}
void Edit()
{
    while(1)
    {
    //after entering the choice that the user want to edit his record, we ask him if he want to edit his name or his password
	    u32 choice;
		while(1)
		{

            printf("                       1-->Edit your password                       2-->Edit your name\n\n");
			ES current_error_state=take_number(&choice);
		    Error(current_error_state);
			if(current_error_state==valid) break;
		}




    switch(choice)
    {
    case 1:
        //function to edit his password
        edit_your_password();
        break;
    case 2:
        //function to edit his name
        edit_your_name();
        break;
    }
    printf("\n                 Do You Want Back To Sub choice`s Enter 1 And If Not Enter 0\n\n");
    u32 dession;
    scanf("%d",&dession);
	clearScreen();
    if (dession!=1)
        break;
   }
}
void edit_your_password()
{
    u8 New_pass[MAX_LENGTH];
    u8 c;
    u32 i;
    printf("                       Enter New Password:\n\n");
    for (i = 0; i < MAX_LENGTH; i++) {
        c = getch();
        if(c == 13)
            break;
        printf("*");
        New_pass[i]=c;
    }
    printf("\n");
	strcpy(ptrfind->Password,New_pass);
}
void edit_your_name()
{
    u8 New_Name[MAX_LENGTH];
    printf("                       Enter New Name:\n\n");
    scanf("%s",&New_Name);
	strcpy(ptrfind->Name,New_Name);
}
