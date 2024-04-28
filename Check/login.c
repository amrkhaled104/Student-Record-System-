#include "include.h"


FILE *file;
char username[MAX_LENGTH];
char password[MAX_LENGTH];
char file_username[MAX_LENGTH];
char file_password[MAX_LENGTH];
extern struct STUDENTS * Head;
ES login(u32 choice)
{
	struct STUDENTS *Help=Head;
	u8 c;
	u32 i = 0;

	switch (choice)
	{
		//check admin
		case 1:

				// افتح ملف النص للقراءة
				file = fopen("admin.csv", "r");
				if (file == NULL)
				{
					printf("Unable to open file.\n");
					return 0;
				}

				// اقرأ اسم المستخدم من الملف حتى الفاصلة
				while ((c = fgetc(file)) != EOF && c != ',')
				{
					file_username[i++] = c;
				}
				file_username[i] = '\0'; // إضافة نهاية السلسلة

				// اقرأ كلمة المرور من الملف بعد الفاصلة
				i = 0;
				while ((c = fgetc(file)) != EOF && c != '\n')
				{
					file_password[i++] = c;
				}
				file_password[i] = '\0'; // إضافة نهاية السلسلة

				// أغلق ملف النص
				fclose(file);

				u8 c;
				printf("\n                                    Enter Username:");
				scanf("%s", username);
				printf("                                      Enter password:");
				for (i = 0; i < MAX_LENGTH; i++)
                {
                c = getch();
                if(c == 13)
                   break;
                printf("*");
                password[i]=c;
                }

				// قارن الاسم وكلمة المرور
				if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
				{

					printf("\n\t\t\t              <-Login successful!-> \n\n\n"
					"\n\t\t\t        ****************************************"
					"\n\t\t\t        ***********             ****************"
					"\n\t\t\t        ***********             ****************"
					"\n\t\t\t        ***********             ****************"
					"\n\t\t\t        =    <WELCOME Amooooooooooooor>        ="
					"\n\t\t\t        ***********             ****************"
					"\n\t\t\t        ***********             ****************"
					"\n\t\t\t        ***********             ****************"
					"\n\t\t\t        ****************************************"
					"\n\n");
					return valid;
				}
				else
				{
					printf("\n\n                                      Invalid username or password\n");
					return notvalid;
	            }


		//check user
		case 2:

		    printf("\n                                      Enter Id:\n"); u32 ID_CHECK;scanf("%d",&ID_CHECK);
			if(Head)
			{
				while(Help)
				{
					if(Help->Id==ID_CHECK)
					{
						printf("                                      <Login successful!>\n\n                                    <WELCOME %s>\n",Help->Name);
						return valid;
					}
					else if (Help->Id!=ID_CHECK)
					{
						if(Help->NEXT==NULL)
						{
							printf("                                      \nThis Id Doesnt Exist\n");
							break;
						}
					}
					Help=Help->NEXT;
				}
			}
			else
			{
				printf("                                      No Data Exist\n");
			 return notvalid;
			}


				break;
		}

}

