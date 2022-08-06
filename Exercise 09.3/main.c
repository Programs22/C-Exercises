#include <stdio.h>

int main(){
    int number, new=0;
    printf("Enter a number\n");
    scanf("%d", &number);
    while(number>0){
        new=new*10+number%10;
        number/=10;
    }
    printf("The new number is %d\n", new);
    return 0;
}
