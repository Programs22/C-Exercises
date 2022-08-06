#include <stdio.h>

int main(){
    int number1, number2;
    printf("Enter the two numbers\n");
    scanf("%d", &number1) ;
    scanf("%d", &number2) ;
    if(number1>number2)
        printf("%d is bigger than %d\n", number1, number2);
    else if(number1<number2)
        printf("%d is bigger than %d\n", number2, number1);
    else
        printf("The numbers are equal");
    return 0;
}
