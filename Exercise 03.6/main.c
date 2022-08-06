#include <stdio.h>

int main() {
    char c1, c2, c3, c4, c5; //The letter 'c' is used to shorten the word character
    printf("Enter five letters\n");
    scanf("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);
    printf("%c%c%c%c%c", c5, c3, c2, c1, c4);
    return 0;
}
