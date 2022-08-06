#include <stdio.h>

int main(){
    int number1, number2;
    printf("Enter the two numbers\n");
    scanf("%d%d", &number1, &number2);
    if(number1%2==0)
        printf("%d is even\n", number1);
    else
        printf("%d is not even\n", number1);
    if(number2%2==0)
        printf("%d is even\n", number2);
    else
        printf("%d is not even\n", number2);
    return 0;
}
