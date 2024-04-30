#include "include.h"
u32 Logout;
void system_init()
{
	u8 i=0;
	while(1)
	{
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
			    break;
		    } 
		    else
		    {
			    Logout=0;
		    }
		  
		}
	

		u32 choice=0,i=0;
		if(choice==1||choice==2||i==0){
	    deco();
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
			deco();
			if(current_error_state==valid) break;
			
		}

		switch(choice)
		{
			case 1:
			      if(login(choice)==valid)
				  {
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
		if(Logout) {
		
		printf("                            Bya Bya Htw7shniiiiiiiiii ");

		break;
    }
	}

}

extern struct STUDENTS * Head;
struct STUDENTS* HELP=NULL;
char* takestring_v2(){
    char* s = (char *)calloc(1,sizeof(char));
    int len = 1;
    *s = '\0';
    char t;
    t = getchar();
    int c = 1;
    while(t != '\n'){
        if(c == len)
        {
            s = (char *)realloc(s, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(s + c - 1) = t;
        *(s + c) = '\0';
        c++;
        t = getchar();
    }
	fflush(stdin);
	if(len == 1)  return takestring_v2();
	if(*s == ' ') {
		printf("Cannot Start With Spaces!\nEnter Again: ");
		return takestring_v2();
	}

    return s;
}
ES take_number(u32 *choise)
{
	*choise=0;
	char *str=takestring_v2();
	u32 i=0;
	while(str[i])
	{
		*choise*=10;
		if(str[i]>='0'&&str[i]<='9')
		{
			*choise+=str[i++]-'0';
		}
		else
		{
			*choise=0;
			return notnumber;
		}
	}
	if(*choise==1e8) return overflow;
	return valid;
}
void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void Error(ES current_error_state)
{
		if(current_error_state==overflow)
		{
			printf("                                      OVERFLOW\n");
		}
		else if(current_error_state==notnumber)
		{
			printf("                                      NOT NUMBER\n\n");
		}
}

void save_data()
{
	HELP=Head;
	while(HELP!=NULL)
	{

		FILE *file = fopen("STUDENTS.csv", "a");
		if (file == NULL) {
			printf("                                            Error opening file.\n");
			exit(1);
		}

		fprintf(file, "%s,%d,%d,%s,%s\n", HELP->Name,HELP->Grade,HELP->Id,HELP->Gender,HELP->Password);
		HELP=HELP->NEXT;
		fclose(file);
	}
}

void clear_list()
 {
    while (Head != NULL)
        {
        struct STUDENTS *ptr = Head;
        Head = Head->NEXT;
        free(ptr);
        }
 }

void load_data()
 {
    clear_list();
    FILE *file = fopen("STUDENTS.csv", "r");
    if (file == NULL)
        {
        printf("Error opening file.\n");
        exit(1);
        }

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        struct STUDENTS *newStudent = (struct STUDENTS *)malloc(sizeof(struct STUDENTS));
        if (newStudent == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        sscanf(line, "%99[^,],%d,%d,%99[^,],%s\n", newStudent->Name, &newStudent->Grade, &newStudent->Id, newStudent->Gender, newStudent->Password);

        // ربط العنصر الجديد بالقائمة المتسلسلة
        newStudent->NEXT = Head;
        Head = newStudent;
    }

    fclose(file);
}
int welcome_admin() {
    char Username[50];
    char Pasword[50];
	
    FILE *file;
    long size;

   
    file = fopen("admin.csv", "r");

   
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // انتقل إلى نهاية الملف
    fseek(file, 0, SEEK_END);

    // احصل على موقع المؤشر (حجم الملف)
    size = ftell(file);
    
    // إعادة ضبط المؤشر إلى بداية الملف
    rewind(file);

    // التحقق من حجم الملف
    if (size == 0) {
        printf("\n\n\n                                             Enta Enharda Sa7eb El Ma7roba Dee\n\n\n                                            Eb3t B2it El7isaB Ya S7bii\n\n");
		sleep(5);
		clearScreen();
		printf("                                                   Now you will enter the data to the system owner\n\n\n");
		sleep(2);
		deco();
        printf("                                                   Enter Username: ");
        scanf("%s", Username); deco();
        printf("                                                   Enter Pasword: ");
		u32 i=0;u8 c;
        for (i = 0; i < MAX_LENGTH; i++)
				{
					c = getch();
					if(c == 13)
					   break;
					printf("*");
					Pasword[i]=c;
				}
				Pasword[i]='\0';
				deco();

        // إعادة فتح الملف للكتابة
        fclose(file);
        file = fopen("admin.csv", "w");
        if (file == NULL) {
            printf("                                                   Error opening file.");
            exit(1);
        }

        // كتابة البيانات إلى الملف
        fprintf(file, "%s,%s\n", Username, Pasword);

        // إغلاق الملف
        fclose(file);
		//EXIT();
       return 1;		
    } else {
        fclose(file);
        return 0;
    }
}
void deco(){
		clearScreen();
		printf("\n\n\n\n\n\n\n                                                   loading");
        for(int i=0;i<3;i++)
            {
                printf(".");
                sleep(1);
            }
		clearScreen();
}