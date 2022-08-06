#include <stdio.h>

int main(){
    int number1, number2, number3 ;
    int sum, product;
    printf("Enter the three numbers\n");
    scanf("%d", &number1);
    scanf("%d", &number2);
    scanf("%d", &number3);
    sum=number1+number2+number3;
    product=number1*number2*number3;
    printf("The average of the three numbers is %d\n", sum/3) ;
    printf("The sum of the three numbers is %d\n", sum) ;
    printf("The product of the three numbers is %d\n", product);
    return 0;
}
