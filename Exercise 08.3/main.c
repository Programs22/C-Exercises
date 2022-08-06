#include <stdio.h>

#define size 100

int palindrome(char s[]);

int main(){
    char string[size];
    printf("Enter a string to check if it is a palindrome\n");
    scanf("%s", string);
    if(palindrome(string)==1)
        printf("The string is a palindrome\n");
    else
        printf("The string isn't a palindrome\n");
    return 0;
}

int palindrome(char s[]){
    int count=0, start, end;
    while(s[count]!='\0')
        count++;
    end=count-1;
    for(start=0;start<=count/2;start++){
        if(s[start]!=s[end])
            return 0;
        end--;
    }
    return 1;
}
