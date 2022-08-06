#include <stdio.h>

int main(){
    int n, counter, i, sum; // Counter i is used as a counter to check the divisors
    printf("Enter a number\n");
    scanf("%d", &n);
    for(counter=2;counter<=n;counter++){ // 1 can't be a perfect number, so we exclude 1 from the check
        sum=0;
        for(i=1;i<=counter/2;i++){
            if(counter%i==0)
                sum+=i;
        }
        if(counter==sum)
            printf("%d is a perfect number\n", counter);
    }
    return 0;
}
