#include <stdio.h>

int main(){
    int number, remainder;
    printf("Enter a number\n");
    scanf("%d", &number);
    remainder=number%2;
    switch(remainder){ // If we do a switch case without a break after each case, all the instructions after the correct case get done
        case 0:
            printf("%d is an even number\n", number);
        case 1:
            printf("%d is not an even number\n", number);
        default:
            printf("Not a valid number entered");
    }
    return 0;
}
