#include <stdio.h>

int main(){
    int number, sum=0;
    printf("Enter a number, if you want to stop enter -1\n");
    scanf("%d", &number);
    while(number!=-1){
        sum+=number;
        printf("Enter a number, if you want to stop enter -1\n");
        scanf("%d", &number);
    }
    printf("The sum is %d", sum);
    return 0;
}
