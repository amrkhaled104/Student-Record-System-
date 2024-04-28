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

void Admin_choice()
{
	while(1){


        u32 choice=0;
		while(1)
		{

	      	printf("                              1-->Add student record                                      2-->Remove student record\n");
		    printf("                                                                  3-->View              \n");
		    printf("                              4-->Edit admin password                                     5-->Edit Info Student \n");
			ES current_error_state=take_number(&choice);
		    Error(current_error_state);
			if(current_error_state==valid) break;
		}

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
	   		printf("\n                       Anthor Process(1->Y  | 0->N)\n");u8 dession;scanf("%d",&dession);
			if (dession!=1) break;
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
	printf("                                      Enter Name:\n");gets(SNew->Name);
	fflush(stdin);
	printf("                                      Enter Grade:\n");scanf("%d",&SNew->Grade);
	u32 flag=0;
	while(1)
    {
		CheckID=Head;
		printf("                                      Enter ID:\n");scanf("%d",&SNew->Id);
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
	
	printf("                                      Enter Gender:\n");scanf("%s",&SNew->Gender);
	printf("                                      Enter Password:\n");
	u8 c;
    for (u32 i = 0; i < MAX_LENGTH; i++)
    {
        c = getch();
        if(c == 13)
          break;
        printf("*");
        SNew->Password[i]=c;
    }
}
void View()
   {
		printf("                                      1-->View student record                                      2-->View all records\n");
		u32 Number ;
		while(1)
		{
			ES current_error_state=take_number(&Number);
		    Error(current_error_state);
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
		printf("                                                     Mafesh Lsa Tolaaaab Ya Admin\n");
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
	while(Helpveiw2!=NULL)
	{
		int i=0;
		if(i++==0)    printf("                         Student Information                     \n");

	  if(Helpveiw2->Id==user_id)
	  {
		  found =1 ;
		  printf("                       Name: %s\n                       Grade: %d\n                       ID: %d\n                       Gender: %s\n                       Password: %s\n", Helpveiw2->Name, Helpveiw2->Grade,Helpveiw2->Id, Helpveiw2->Gender, Helpveiw2->Password);
		  break;
	  }
	  Helpveiw2= Helpveiw2->NEXT ;
	}

	if (!found) printf("                       Student with ID %d Not Found Ya Admoooooooooooooooooon.\n", user_id);
}
void Remove_student_record()
 {
   u32 User_Id;printf("\n                       Enter Id :");scanf("%d",&User_Id);
// عايزين نضيف لو اليوز مكنشي موجود اصلا
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
   }
   else
   {
	   printf("No Data\n");
   }
}
void Edit_admin_password()
{
	char username[MAX_LENGTH];
    char newPassword[MAX_LENGTH];
	// اسم المستخدم الحالي وكلمه المرور الجديده
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", newPassword);

	updatePasswordInFile(username, newPassword);
	printf("Password updated successfully!\n");
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
		while(1)
		{
			printf("                       1-->Edit Student Grade                       2-->Edit Student Name\n");
			ES current_error_state=take_number(&choice);
			Error(current_error_state);
			if(current_error_state==valid) break;
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
		printf("\n                       Anthor Process(1->Y  | 0->N)\n");u32 dession;scanf("%d",&dession);
		if (dession!=1) break;
   }
}


void Edit_student_grade()
{
	Helpgrade=Head;
    u32 student_id;
    u32 new_grade;
    u32 found = 0;

    printf("                       Enter student ID: ");
    scanf("%d", &student_id);

    while (Helpgrade != NULL)
    {
        if (Helpgrade->Id == student_id)
        {
            found = 1;
            //printf("                 WELCOME %s                ",Helpgrade ->Name) ملوش لازمه اصل الادمن الي هيعدل ف انت بترحب باليوزر ليه ؟

            printf("                       Enter new grade for student : ");
            scanf("%d",&new_grade);
            Helpgrade->Grade = new_grade;

            printf("                       Grade for student %s has been updated successfully \nI doubt that you are falsifying the answer hhhh", Helpgrade ->Name);
            break;
        }
        Helpgrade = Helpgrade ->NEXT;
    }

    if (!found)
    {
        printf("                       Student with ID %d not found You cannnnot Hack the system \n", student_id);
    }
}



void Edit_student_name()
{
		u32 student_id;
		u8 new_name[MAX_LENGTH];
		u32 found = 0;
		Helpname=Head;

		printf("                       Enter student ID: ");
		scanf("%d",&student_id);

		while (Helpname != NULL)
		{
			if (Helpname->Id == student_id)
			{
				found = 1;
				printf("                       Enter new name for student : ");

				fflush(stdin);
				gets(new_name);

				printf(                       "Name for student %s has been updated successfullly and become %s ", Helpgrade ->Name ,new_name);
				strcpy(Helpname->Name,new_name);
				break;
			}
			Helpname = Helpname ->NEXT;
		}

		if (!found)
		{
			printf("                       Student with ID %d not found You cannnnot Hack the system \n", student_id);
		}
}
