#include <stdio.h>

int GCD(int x, int y);

int main(){
    int x, y; //x and y are the two numbers
    printf("Enter the two numbers\n");
    scanf("%d%d", &x, &y);
    printf("The greatest common divisor of %d and %d is %d\n", x, y, GCD(x,y));
    return 0;
}

int GCD(int x, int y){
    int smaller, GCD=1, counter;
    if(x<y)
        smaller=x;
    else
        smaller=y;
    for(counter=2;counter<=smaller;counter++){
        if(x%counter==0&&y%counter==0)
            GCD=counter;
    }
    return GCD;
}
