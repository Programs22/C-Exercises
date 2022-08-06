#include <stdio.h>

int main(){
    int counter=1, sum=0;
    while(counter<=10){
        sum+=counter;
        counter++;
    }
    printf("The sum of all the numbers up to 10 is %d\n", sum);
    return 0;
}
