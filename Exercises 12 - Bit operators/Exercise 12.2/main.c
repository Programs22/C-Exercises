#include <stdio.h>

void reorderBits(unsigned number);

int main(){
    unsigned number;
    printf("Enter the number\n");
    scanf("%u", &number);
    reorderBits(number);
    return 0;
}

void reorderBits(unsigned number){
    int i; // Counter
    unsigned numberOfBits=sizeof(number)*8;
    unsigned int new=0;
    unsigned c;
    unsigned mask=1<<31;
    for(i=0;i<numberOfBits;i++){
        if((number&(1<<i)))
            new|=1<<((numberOfBits-1)-i);
    }
    printf("%u=", number);
    for(c=1;c<=32;c++){
        putchar(number&mask?'1':'0');
        number<<=1;
        if(c%8==0)
            printf(" ");
    }
    printf("\n%u=", new);
    for(c=1;c<=32;c++){
        putchar(new&mask?'1':'0');
        new<<=1;
        if(c%8==0)
            printf(" ");
    }
}
