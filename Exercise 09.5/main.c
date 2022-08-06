#include <stdio.h>

#define size 100

int isPrime(int n);

int main(){
    int n, i, j=0; // i and j are counters
    int primes[size], power[size]={0};
    printf("Enter a number\n");
    scanf("%d", &n);
    for(i=2;i<=n;i++){
        if(isPrime(i)==1){
            primes[j]=i;
            j++;
        }
    }
    for(i=0;i<j;i++){
        if(n>0&&n%primes[i]==0){
            power[i]++;
            n/=primes[i];
            while(n>0&&n%primes[i]==0){
                power[i]++;
                n/=primes[i];
            }
        }
    }
    printf("The number represented as a multiple of prime numbers is\n");
    for(i=0;i<j;i++){
        printf("%d^%d*", primes[i], power[i]);
    }
    return 0;
}

int isPrime(int n){
    int i;
    for(i=2;i<=n/2;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}