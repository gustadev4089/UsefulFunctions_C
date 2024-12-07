#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STRING_SIZE 100

char* string_between(char start, char end, char *full_string);

int main(void){

    printf("-------- String Between --------- \n");

    char *string_test = calloc(sizeof(char), STRING_SIZE);
    char *string_return = calloc(sizeof(char), STRING_SIZE);

    strncpy(string_test, "This is a phrase to make a (test) and 'nothing more'. ", STRING_SIZE);
    

    char start = '\'';
    char end = '\'';

    string_return = string_between(start, end, string_test);
    

    printf("That is the return --> %s \n", string_return);

    return 0;
}

char* string_between(char start, char end, char *full_string){

    char *string_return = calloc(sizeof(char), 25);
    short iterator = 0;
    short i_copy = 0;
    _Bool can_copy = false;


    while(*(full_string+iterator) != '\0'){

        if(*(full_string+iterator) == end && can_copy){
            can_copy = false;
            iterator++;
            *(string_return+iterator) = '\0';
            return string_return;
        }


        if(can_copy){
            *(string_return+i_copy) = *(full_string+iterator);
            i_copy ++;
        }


        if(*(full_string+iterator) == start){
            can_copy = true;
        }

        iterator ++;
    }

    strncpy(string_return, "Not found.", 25);

    return string_return;
}