#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>


#define ADDRESS_SIZE 30

char* address_v4(char *string);

int main(void){

    address_v4("Nmap scan report for XXXXXXX (192.168.100.5)");
    address_v4("Host is up (0.0019s latency).");
    address_v4("Nmap scan report for 192.168.100.23");
    address_v4("Host is up (0.0067s latency).");

    return 0;
}

char* address_v4(char *string){
    regex_t regex; // <-- Var regex

    regmatch_t match[1]; // <-- Var match regex

    char *ip_address = calloc(sizeof(char), ADDRESS_SIZE);

    const char *pattern = "[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}"; // <-- Pattern IP address V4

    int ret = regcomp(&regex, pattern, REG_EXTENDED);



    if(ret != 0){  
        regfree(&regex);  
        printf("Error !!! \n");
        return "Error";
    }

    ret = regexec(&regex, string, 1, match, 0); // Save result of match

    if(ret == 0){ // Has match
        
        for(int c = match[0].rm_so; c < (match[0].rm_eo); c++){
            *(ip_address+(c - (match[0].rm_so))) = *(string+c); 
        }

        printf("%s \n", ip_address);

        regfree(&regex);

        return ip_address;

    }else{
        regfree(&regex);
        printf("No match \n");
        return "NULL";
    }
}
