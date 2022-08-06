#include <stdio.h>

int main(){
    int day, month, year;
    printf("Enter the date in any of these formats: yy/mm/dd; yy-mm-dd; yy+mm+dd\n");
    scanf("%d%*c%d%*c%d%*c", &year, &month, &day);
    printf("The year is %d, %d ", year, day);
    switch(month){
        case 1: printf("January"); break;
        case 2: printf("February"); break;
        case 3: printf("March"); break;
        case 4: printf("April"); break;
        case 5: printf("May"); break;
        case 6: printf("June"); break;
        case 7: printf("July"); break;
        case 8: printf("August"); break;
        case 9: printf("September"); break;
        case 10: printf("October"); break;
        case 11: printf("November"); break;
        case 12: printf("December"); break;
        default: printf("This month doesn't exist\n"); break;
    }
    return 0;
}
