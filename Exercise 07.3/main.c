#include <stdio.h>

int Revert(int number);

int main(){
    int number;
    printf("Enter a number\n");
    scanf("%d", &number);
    printf("The reverted number of %d is %d\n", number, Revert(number));
    return 0;
}

int Revert(int number){
    int new=0;
    while(number>0){
        new=new*10+number%10;
        number/=10;
    }
    return new;
}
