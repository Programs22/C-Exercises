#include <stdio.h>

int main(){
    int a, b, c, d, e, number; //a, b, c, d, e are the variables that will take each of the five digits, from left to right
    printf("Enter a five digit number\n");
    scanf("%d", &number);
    a=number/10000;
    b=(number%10000)/1000;
    c=(number%1000)/100 ;
    d=(number%100)/10 ;
    e=number%10 ;
    printf("%d %d %d %d %d\n", a, b, c, d, e);
    return 0;
}
