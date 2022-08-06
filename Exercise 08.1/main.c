#include <stdio.h>

#define size 31

int main(){
    float temperatures[size];
    int counter, days, month;
    float sum=0.0;
    printf("Enter the number of the month\n");
    scanf("%d", &month);
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: days=31; break;
        case 4:
        case 6:
        case 9:
        case 11: days=31; break;
        case 2: days=28; break;
        default: printf("This month doesn't exist\n"); break;
    }
    for(counter=0;counter<days;counter++){
        printf("Enter a temperature for day %d of this month\n", counter+1);
        scanf("%f", &temperatures[counter]);
        sum+=temperatures[counter];
    }
    printf("The average temperature of this month was %.3f\n", sum/days);
    return 0;
}
