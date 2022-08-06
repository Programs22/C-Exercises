#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *string, *string1, *string2, *string3, *remainder;
    char code[10];
    int i;
    long int l;
    printf("Enter a string\n");
    gets(string);
    string1=strtok(string," ");
    string2=strtok(NULL,"-");
    string3=strtok(NULL," ");
    memcpy(code,&string1[1],3);
    strcat(string2,string3);
    i=atoi(code);
    l=strtol(string2,&remainder,0);
    printf("The country code is %d and the telephone number is %ld\n", i, l);
    return 0;
}
