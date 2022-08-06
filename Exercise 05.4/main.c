#include <stdio.h>

int main(){
    int number;
    printf("Enter a number, maximum of 4 digits\n");
    scanf("%d", &number);
    printf("%d in roman numerals is: ", number);
    while(number>0){
        if(number>=1000&&number<10000){
            printf("M");
            number-=1000;
        }
        else if(number>=500&&number<1000){
            printf("D");
            number-=500;
        }
        else if(number>=100&&number<500){
            printf("C");
            number-=100;
        }
        else if(number>=50&&number<100){
            printf("L");
            number-=50;
        }
        else if(number>=10&&number<50){
            printf("X");
            number-=10;
        }
        else if(number>=5&&number<10){
            if(number==9){
                printf("IX");
                number-=9;
            }
            else{
                printf("V");
                number-=5;
            }
        }
        else if(number>=1&&number<5){
            if(number==4){
                printf("IV");
                number-=4;
            }
            else{
                printf("I");
                number-=1;
            }
        }
    }
    return 0;
}
