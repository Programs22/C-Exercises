#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c; // a, b, and c are the numbers we will check
    for(c=2;c<=100;c++){
        for(b=2;b<=100;b++)
            for(a=2;a<=100;a++){
                if(pow(c,2)==(pow(a,2)+pow(b,2)))
                    printf("Pythagorean triplet: %d %d %d\n", a, b, c);
            }
    }
    return 0;
}
