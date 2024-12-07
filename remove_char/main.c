#include <stdio.h>
#include <stdlib.h>


#define SCAN_CONTENT_LENGTH 170



void remove_char(char *content, char remove){
    int add = 0;

    while(*(content+add) != '\0'){

        if(*(content+add) ==  remove){
            *(content+add) = '\0';
            *(content+add+1) = ' ';

            add--;
        }
        
        add ++;
    }
}



int main(void){
    char *scan_content = malloc(sizeof(char) * SCAN_CONTENT_LENGTH);

    printf("-------- Remove_Char --------- \n");

    printf("Enter to something: ");

    fgets(scan_content, SCAN_CONTENT_LENGTH, stdin); // Get it content with the character (\n)

    remove_char(scan_content, '\n'); // <-- Removing the character (\n), not to generate problems in the program


    printf("%s <-- ", scan_content);
    
    // After to print message above, skip line using printf();
    printf("\n");


    return 0;
}