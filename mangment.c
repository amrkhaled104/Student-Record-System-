#include "include.h"
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
			printf("Error opening file.\n");
			exit(1);
		}

		fprintf(file, "%s,%d,%d,%s,%s\n", HELP->Name,HELP->Grade,HELP->Id,HELP->Gender,HELP->Password);
		HELP=HELP->NEXT;
		fclose(file);
	}
}

void load_data() {
    FILE *file = fopen("STUDENTS.csv", "r");
    if (file == NULL) {
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

