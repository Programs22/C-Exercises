#include <stdio.h>

int main(){
    int counter=0, product=1, number;
    while(counter<10){
        printf("Enter a number\n");
        scanf("%d", &number);
        product*=number;
        counter++;
    }
    printf("The product is %d", product);
    return 0;
}
