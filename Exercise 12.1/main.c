#include <stdio.h>

void MultiplyByPower2(unsigned number, int power);

int main(){
    unsigned number;
    int power;
    printf("Enter a number\n");
    scanf("%u", &number);
    printf("Enter an exponent\n");
    scanf("%d", &power);
    MultiplyByPower2(number,power);
    return 0;
}

void MultiplyByPower2(unsigned number, int power){
    unsigned c; // Counter
    number<<=power;
    unsigned mask=1<<31;
    printf("%u=",number);
    for(c=1;c<=32;c++){
        putchar(number&mask?'1':'0');
        number<<=1;
        if(c%8==0)
            printf(" ");
    }
}
