#include "include.h"

struct STUDENTS * Head=NULL;
struct STUDENTS*HelpAdd=NULL;
struct STUDENTS *Helpveiw1=NULL;
struct STUDENTS *Helpveiw2=NULL;
struct STUDENTS *Helpdelete=NULL;
struct STUDENTS *Saveprev=NULL;
struct STUDENTS *Helpgrade=NULL;
struct STUDENTS*Helpname = NULL;
struct STUDENTS *CheckID = NULL;
struct STUDENTS *HelpCheck =NULL;
extern u32 Logout;
void Admin_choice()
{
	while(1){
		     u32 choice=100;
             b:if(choice==0) {
				 Logout=1;
                 break;				
			 } 


		a:while(1)
		{	     
            printf("                                                                  [3]-->View              \n"); 	
	      	printf("                              [1]-->Add student record                                      [2]-->Remove student record\n");
		    printf("                              [4]-->Edit admin password                                     [5]-->Edit Info Student \n");
			printf("                                                                 [0]-->LOGOUT\n");

			ES current_error_state=take_number(&choice);
		    Error(current_error_state);
		    deco();
			if(current_error_state==valid) break;
		}
		if(choice!=0&&choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5)
		{
			clearScreen();
			 printf("                            Foucs Please ([1] or [2]or [3]or [4]or [5])\n\n ");sleep(2);deco();
			goto a;
	    }
		if(choice==0) goto b;
       clearScreen();
	   switch(choice)
	   {
		    case 1:
				Add_student_record();
		    break;
		    case 2:
				Remove_student_record();
		    break;
		    case 3:
				View();
		    break;
		    case 4:
				Edit_admin_password();
		    break;
		    case 5:
				Edito();
		    break;
	   }
	   u32 dessionn;
	  aa:while(1)
	   {
		    printf("\n                       Anthor Process([1]->Y  | [0]->N)\n");
			ES current_error_state=take_number(&dessionn);
		    Error(current_error_state);
			deco();
	        if(current_error_state==valid) break;
	   }
			clearScreen();
			if(dessionn!=0&&dessionn!=1)
		    {
			    printf("Foucs Please ([1] or [0])\n\n ");sleep(2);deco();
				goto aa;
			}
			else if (dessionn==0) break;
   
   }
}


void Add_student_record()
{
	struct STUDENTS *SNew;
	if(Head==NULL)
	{
		SNew=(struct STUDENTS*)malloc(sizeof(struct STUDENTS));
		Head=SNew;
	}
	else
	{
		HelpAdd=Head;
		while(HelpAdd->NEXT!=NULL)
			HelpAdd = HelpAdd->NEXT;
		SNew=(struct STUDENTS*)malloc(sizeof(struct STUDENTS));
		HelpAdd->NEXT=SNew;
	}
	SNew->NEXT=NULL;
	fflush(stdin);
	printf("                                      Now You Enter Data Please Foucs\n\n");
	printf("                                      Enter Name:\n");gets(SNew->Name);deco();
	fflush(stdin);
	printf("                                      Enter Grade:\n");scanf("%d",&SNew->Grade);deco();
	u32 flag=0;
	while(1)
    {
		CheckID=Head;
		printf("                                      Enter ID:\n");scanf("%d",&SNew->Id);deco();
        while(CheckID->NEXT!=NULL)
        {
            if(CheckID->Id==SNew->Id)
            {
                printf("          This ID Is Exist ,Try Again \n");
				break;
            }
            else
            {
				 CheckID = CheckID->NEXT;
            }
        }
		if(CheckID->NEXT==NULL) break;
    }
	
	printf("                                      Enter Gender:\n");scanf("%s",&SNew->Gender);deco();
	printf("                                      Enter Password:\n");
	u8 c;u32 i;
    for (i = 0; i < MAX_LENGTH; i++)
    {
        c = getch();
        if(c == 13)
          break;
        printf("*");
        SNew->Password[i]=c;
    }
	SNew->Password[i] = '\0';
	deco();
}
void View()
   {
		printf("                                      1-->View student record                                      2-->View all records\n");
		u32 Number ;
		while(1)
		{
			ES current_error_state=take_number(&Number);
		    Error(current_error_state);
			deco();
			if(current_error_state==valid) break;
		}

		switch (Number)
		{
				case 1:
				   View_student_record() ;
				break;

				case 2:
				   View_all_records() ;
				break;

		}
   }
void View_all_records()
{
	Helpveiw1=Head;
	u32 counter_Client=0;
	if(Helpveiw1==NULL)
	{
		printf("                                                     Mafesh Lsa Tolaaaab Ya Admin\n");sleep(2);deco();
	}
	int i=0;
	while(Helpveiw1!=NULL)
	{
		if(i++==0)
		printf("                                                     STUDENTS LIST                                                         \n");

		printf("                       <-STUDENT[%d]->\n                       Name:%s\n                       Grade:%d\n                       ID:%d\n                       Gender:%s\n                       Password:%s\n\n\n",++counter_Client,Helpveiw1->Name,Helpveiw1->Grade,Helpveiw1->Id,Helpveiw1->Gender,Helpveiw1->Password);
		Helpveiw1=Helpveiw1->NEXT;
	}
}


void View_student_record ()
{

    u32 found =0 ;
    u32 user_id=0;
    printf("Enter Id :");scanf("%d",&user_id);
	Helpveiw2=Head;
	int i=0;
	while(Helpveiw2!=NULL)
	{
		if(i++==0)    printf("                         Student Information                     \n");

	  if(Helpveiw2->Id==user_id)
	  {
		  found =1 ;
		  printf("                       Name: %s\n                       Grade: %d\n                       ID: %d\n                       Gender: %s\n                       Password: %s\n", Helpveiw2->Name, Helpveiw2->Grade,Helpveiw2->Id, Helpveiw2->Gender, Helpveiw2->Password);
		  break;
	  }
	  Helpveiw2= Helpveiw2->NEXT ;
	}

	if (!found) printf("                       Student with ID %d Not Found Ya Admoooooooooooooooooon.\n", user_id);sleep(2);deco();
}
void Remove_student_record()
 {
   u32 User_Id;printf("\n                       Enter Id :");scanf("%d",&User_Id);
   if(Head)
   {
	  Helpdelete=Head;

      while(Helpdelete)
      {
          if(Helpdelete->Id==User_Id)
          {
            if(Saveprev)
			{
                Saveprev->NEXT=Helpdelete->NEXT;
			}

            else
			{
              Head=Helpdelete->NEXT;
            }
        free(Helpdelete);
      }
      Saveprev=Helpdelete;
      Helpdelete=Helpdelete->NEXT;
    }
	printf("                                                              Done");sleep(2);deco();
   }
   else
   {
	   printf("                                                           No Data\n");sleep(2);deco();
   }
}
void Edit_admin_password()
{
	char username[MAX_LENGTH];
    char newPassword[MAX_LENGTH];
	// اسم المستخدم الحالي وكلمه المرور الجديده
    printf("                                                          Enter Username: ");
    scanf("%s", username);deco();
    printf("                                                          Enter New Password: ");
    scanf("%s", newPassword);deco();

	updatePasswordInFile(username, newPassword);
	printf("                                                          Password Updated Successfully!\n");sleep(2);deco();
}
// تحديث كلمة المرور في الملف

void updatePasswordInFile(const char *username, const char *newPassword) {
    FILE *file = fopen("admin.csv", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "%s,%s\n", username, newPassword);

    fclose(file);
}
void Edito()
{
    while(1)
    {
		u32 choice;
		aaa:while(1)
		{
			printf("                       1-->Edit Student Grade                       2-->Edit Student Name\n");
			ES current_error_state=take_number(&choice);
			Error(current_error_state);
			deco();
			if(current_error_state==valid) break;
		}
	   if(choice!=1&&choice!=2)
		{
			clearScreen();
			 printf("                            Foucs Please ([1] or [2])\n\n ");sleep(2);deco();
			goto aaa;
	    }

		switch(choice)
		{
		case 1:
			Edit_student_grade();
			break;
		case 2:
			Edit_student_name();
			break;
		}
	   u32 dessionn;
	  aa:while(1)
	   {
		    printf("\n                       Anthor Process([1]->Y  | [0]->N)\n");
			ES current_error_state=take_number(&dessionn);
		    Error(current_error_state);
			deco();
	        if(current_error_state==valid) break;
	   }
			clearScreen();
			if(dessionn!=0&&dessionn!=1)
		    {
			    printf("Foucs Please ([1] or [0])\n\n ");sleep(2);deco();
				goto aa;
			}
			else if (dessionn==0) break;
   
   }
}


void Edit_student_grade()
{
	Helpgrade=Head;
    u32 student_id;
    u32 new_grade;
    u32 found = 0;

    printf("                       Enter student ID: ");
    scanf("%d", &student_id);deco();

    while (Helpgrade != NULL)
    {
        if (Helpgrade->Id == student_id)
        {
            found = 1;
            printf("                       Enter new grade for student : ");
            scanf("%d",&new_grade);deco();
            Helpgrade->Grade = new_grade;

            printf("\n\n                       Grade for student %s has been updated successfully \n                       I doubt that you are falsifying the answer hhhh", Helpgrade ->Name);sleep(2);deco();
            break;
        }
        Helpgrade = Helpgrade ->NEXT;
    }

    if (!found)
    {
        printf("\n\n                       Student with ID %d Not Found  \n", student_id);sleep(2);deco();
    }
}



void Edit_student_name()
{
		u32 student_id;
		u8 new_name[MAX_LENGTH];
		u32 found = 0;
		Helpname=Head;

		printf("                       Enter student ID: ");
		scanf("%d",&student_id);deco();

		while (Helpname != NULL)
		{
			if (Helpname->Id == student_id)
			{
				found = 1;
				printf("                       Enter new name for student : ");

				fflush(stdin);
				gets(new_name);deco();

				printf("                                 Name updated successfullly and become %s ",Helpgrade->Name,new_name);sleep(2);
				strcpy(Helpname->Name,new_name);deco();
				break;
			}
			Helpname = Helpname ->NEXT;
		}

		if (!found)
		{
			printf("                       Student with ID %d Not Found \n", student_id);sleep(2);deco();
		}
}
