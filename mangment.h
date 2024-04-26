#ifndef mang
#define mang
#include "Std_Type.h"
char * takestring_v2();
typedef enum
{
	overflow,
	valid,
	notvalid,
	notnumber

}ES;
void Error(ES current_error_state);
ES take_number(u32 *choise);
void save_data();
void load_data();
#endif
