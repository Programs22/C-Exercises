#include <stdio.h>

int GCD(int x, int y);

int main(){
    int x, y;
    printf("Enter the two numbers\n");
    scanf("%d%d", &x, &y);
    printf("The greatest common divisor of %d and %d is %d\n", x, y, GCD(x,y));
    return 0;
}

int GCD(int x, int y){
    if(x==0||y==0)
        return 1;
    if(x==y)
        return x;
    if(x>y)
        return GCD(x-y,y);
    return GCD(x,y-x);
}
