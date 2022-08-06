#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char flag; // If flag is 'y', the program enters dates. When the flag is 'n', the program stops
    char *string, *day, *month, *year;
    int m; // m is used to hold the month in integer value
    printf("Do you want to enter a date?\n");
    scanf("%c", &flag);
    while(flag!='n'){
        fflush(stdin);
        printf("Enter a date\n");
        gets(string);
        day=strtok(string,"//");
        month=strtok(NULL,"//");
        year=strtok(NULL," ");
        printf("%s ", day);
        m=atoi(month);
        switch(m){
            case 1: printf("January "); break;
            case 2: printf("February "); break;
            case 3: printf("March "); break;
            case 4: printf("April "); break;
            case 5: printf("May "); break;
            case 6: printf("June "); break;
            case 7: printf("July "); break;
            case 8: printf("August "); break;
            case 9: printf("September "); break;
            case 10: printf("October "); break;
            case 11: printf("November "); break;
            case 12: printf("December "); break;
        }
        printf("%s\n", year);
        printf("Do you want to enter a date?\n");
        flag=getchar();
    }
    return 0;
}
