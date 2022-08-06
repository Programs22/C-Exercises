#include <stdio.h>

int main(){
    int number, sum=0;
    char character;
    printf("Enter a number\n");
    scanf("%d", &number);
    sum+=number;
    fflush(stdin); // This function is used to flush the buffer from the standard input in order to enter the character in the next 2 lines
    printf("Do you want to enter more? Enter 'y' for yes, 'n' for no\n");
    scanf("%c", &character);
    while(character!='n'){
        printf("Enter a number\n");
        scanf("%d", &number);
        sum+=number;
        fflush(stdin);
        printf("Do you want to enter more? Enter 'y' for yes, 'n' for no\n");
        scanf("%c", &character);
    }
    printf("The sum is %d\n", sum);
    return 0;
}
