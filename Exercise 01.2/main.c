#include <stdio.h>
/* This program enters 4 numbers from standard input and calculates their sum */
int main(){
    int number1, number2, number3, number4, sum;
    printf("Enter the numbers you want to calculate a sum from\n");
    scanf("%d", &number1);
    scanf("%d", &number2);
    scanf("%d", &number3);
    scanf("%d", &number4);
    sum=number1+number2+number3+number4 ;
    printf("The sum of all the numbers is: %d\n", sum) ;
    return 0;
}
