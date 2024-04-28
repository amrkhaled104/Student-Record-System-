#ifndef admin
#define admin
#define MAX_LENGTH 100


//ba5od eladmin 3iaez ehh
void Admin_choice();
//bsgl us gded
void Add_student_record();
//b5irooo
void View();
//b3red kloo
void View_all_records();
//b3red l wa7ed bs
void View_student_record();
//bmsa7 amooo
void Remove_student_record();
//b3dll paswoediiiiiiii
void Edit_admin_password();
//b3del dargtt talib
void Edit_student_grade();
//b3dl esmooo
void Edit_student_name();
//hna ba5irooo
void Edito();
void updatePasswordInFile(const char *username, const char *newPassword);

//Da assa elila de kolaha hna
struct STUDENTS
    {
        u8 Name[MAX_LENGTH];
        u32 Grade;
        u32 Id;
        u16 Age;
        u8 Gender[MAX_LENGTH];
        u8 Password[MAX_LENGTH];
        struct STUDENTS *NEXT;
    };

#endif
