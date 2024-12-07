#include <stdio.h>
#include <stdlib.h>


char *lower_case(char *string);


int main(void){

    printf("%s \n", lower_case("Teste"));

    return 0;
}


char *lower_case(char *string){

    int iterator_a = 0;
    char *new_string = calloc(sizeof(char), 50);
    char letter = '\0';

    while(*(string+iterator_a) != '\0'){

        letter = *(string+iterator_a);
        if(letter > 'A' && letter < 'Z'){
            *(new_string+iterator_a) = letter+32;
        }else{
            *(new_string+iterator_a) = *(string+iterator_a);   
        }
        
        iterator_a++;
    }

    return new_string;
}