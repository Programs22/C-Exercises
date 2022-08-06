#include <stdio.h>

int Revert(int n);

int main(){
    int n1, n2;
    printf("Enter the values of the interval\n");
    scanf("%d%d", &n1, &n2);
    while(n1<=n2){
        if(n1%Revert(n1)==0)
            printf("%d meets the requirements\n", n1);
        n1++;
    }
    return 0;
}

int Revert(int n){
    int number=0;
    while(n>0){
        number=number*10+n%10;
        n/=10;
    }
    return number;
}