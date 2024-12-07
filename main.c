#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE_COMMAND_CHOICE 200
#define SIZE_NAME_FUNCTION 500

int main(void){
    
    char *choice_struct = malloc(sizeof(char) * SIZE_COMMAND_CHOICE);
    char *choice = malloc(sizeof(char) * SIZE_NAME_FUNCTION);


    // In this function bellow, i only need put the name of file that i want execute
    
    strncpy(choice, "lower_case",SIZE_NAME_FUNCTION); // <-- choice the function to execute


    sprintf(choice_struct, "cd %s && gcc *.c -o main.out && ./main.out", choice);

    system(choice_struct);

    return 0;
}