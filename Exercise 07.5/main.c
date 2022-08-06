#include <stdio.h>

int Fib(int n);

int main(){
    int n; // This is the Fibonacci number we are looking for
    printf("Enter a value for n\n");
    scanf("%d", &n);
    printf("The Fibonacci number you are looking for is %d\n", Fib(n));
    return 0;
}

int Fib(int n){
    int a=0, b=1, number, counter; // a and b are the previous two Fibonacci numbers in the sequence
    for(counter=2;counter<n;counter++){
        number=a+b;
        a=b;
        b=number;
    }
    return number;
}
