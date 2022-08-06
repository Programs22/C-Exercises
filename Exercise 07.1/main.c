#include <stdio.h>

int Even(int x);

int main(){
    int counter, number;
    for(counter=1;counter<=10;counter++){
        printf("Enter a number\n");
        scanf("%d", &number);
        if(Even(number)==1)
            printf("%d is an even number\n", number);
        else
            printf("%d is not an even number\n", number);
    }
    return 0;
}

int Even(int x){
    if(x%2==0)
        return 1;
    else
        return 0;
}
