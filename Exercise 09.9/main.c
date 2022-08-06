#include <stdio.h>

int main(){
    int n, x, i, j, k; // Parameters from the given problem
    int counter;
    float total;
    printf("Enter the number of starting bacteria\n");
    scanf("%d", &n);
    printf("Enter the value for the parameter i\n");
    scanf("%d", &i);
    printf("Enter the values for parameters j and x\n");
    scanf("%d%d", &j, &x);
    printf("Enter the number of minutes you want to solve for\n");
    scanf("%d", &k);
    for(counter=i;counter<=k;counter+=i){
        n*=2;
    }
    total=n;
    for(counter=j;counter<=k;counter+=j){
        total-=total*((float)x/100);
    }
    printf("The total bacteria remaining after %d minutes is %f\n", k, total);
    return 0;
}
