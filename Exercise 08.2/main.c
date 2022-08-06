#include <stdio.h>

#define size 100

int prime(int number);
void change_primes(int a[], int n);

int main(){
    int array[size];
    int n, counter;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    for(counter=0;counter<n;counter++)
        array[counter]=1;
    change_primes(array,n);
    printf("The prime numbers up to %d are:\n", n);
    for(counter=0;counter<n;counter++){
        if(array[counter]==0)
            printf("%d ", counter);
    }
    return 0;
}

int prime(int number){ // Function to find if a number is a prime number
    int i; // Counter for the subsequent for loop
    if(number==0||number==1)
        return 0;
    for(i=2;i<=number/2;i++){ // Check every divisor from 2 to half of the number being checked
        if(number%i==0)
            return 0;
    }
    return 1;
}

void change_primes(int a[], int n){
    int counter;
    for(counter=0;counter<n;counter++){
        if(prime(counter)==1)
            a[counter]=0;
    }
}
