#ifndef mang
#define mang
#include "Std_Type.h"
//Function receives any input k string
char * takestring_v2();
//To handile error
typedef enum
{
	overflow,
	valid,
	notvalid,
	notnumber

}ES;
//It takes the error type to and prints a message based on it
void Error(ES current_error_state);
//He takes the input and sees if it is correct or error
ES take_number(u32 *choise);
//Save data hhhhhhh 
void save_data();
//load data hhhhhhhh
void load_data();
//btm7iiiiiiiiiiiiiiiiiiiiiiiii
void clear_list();
//btms7 terminal to decoration
void clearScreen();
//system kolo
void system_init();
#endif
