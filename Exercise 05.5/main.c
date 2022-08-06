#include <stdio.h>

int main(){
    int counter;
    for(counter=1;counter<=100;counter++){
        if(counter%3==0)
            continue;
        printf("%d is not divisible by 3\n", counter);
    }
    return 0;
}
