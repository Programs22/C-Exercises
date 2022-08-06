#include <stdio.h>

int main(){
    int sum, number;
    for(sum=0, number=2;number<=100;number+=2){
        sum+=number;
    }
    printf("The sum is %d\n", sum);
    return 0;
}
