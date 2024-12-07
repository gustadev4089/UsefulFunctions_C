#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_INPUT 100

int get_input_analyser(char *input, int size);


int main(void){
    char *input = malloc(sizeof(char) * SIZE_INPUT);
    int input_data;

    printf("Enter a number please: ");

    input_data = get_input_analyser(input, SIZE_INPUT); // Passes variable and it's size, return what is entered
    
    if(input_data < 0){
        printf("Data invalid. \n");
        return 0;
    }

    printf("The number entered is: %i\n", input_data);
    return 0;
}

int get_input_analyser(char *input, int size){ 
    // the purpose of this function is to get data 
    // without '\n' and check for error 

    int result = 0;
    char c;
    int size_data = 0;
    _Bool checked_input = true;
    

    while((c = getchar()) != '\n' && size_data < size){

        if(!(c >= '0' && c <= '9')){ // If not to be a number, not to process the input
            checked_input = false;
        }

        *(input+size_data) = c; // <-- put the data in the slot memorie
        size_data++; 
    }

    
    if(checked_input){ // if to be a number, converter (char) to (int)
        int multi = 1;

        for(int c=size_data-1; c >= 0; c--){
            result += (*(input+c) - 48) * multi; 
            multi *= 10;
        }

        return result; // return result converted
    }

    return -1; // It's not a number
}

