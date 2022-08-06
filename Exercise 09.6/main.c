#include <stdio.h>

int cube(int n);

int main(){
    int n, counter, sum, temp;
    printf("Enter a number\n");
    scanf("%d", &n);
    for(counter=1;counter<n;counter++){
        sum=0;
        temp=counter;
        while(temp>0){
            sum+=cube(temp%10);
            temp/=10;
        }
        if(sum==counter)
            printf("%d meets the requirements\n", counter);
    }
    return 0;
}

int cube(int n){
    return n*n*n;
}
