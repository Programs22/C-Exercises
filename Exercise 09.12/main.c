#include <stdio.h>

#define size 100

int main(){
    int polynomial1[size], polynomial2[size], sum[size];
    int m, n, counter, i, j, temp;
    printf("Enter the values for m and n\n");
    scanf("%d%d", &m, &n);
    for(counter=0;counter<m;counter++){
        printf("Enter a coefficient of the polynomial\n");
        scanf("%d", &polynomial1[counter]);
    }
    for(counter=0;counter<n;counter++){
        printf("Enter a coefficient of the polynomial\n");
        scanf("%d", &polynomial2[counter]);
    }
    if(m>n){
        i=0;
        j=0;
        temp=m;
        while(temp>n){
            sum[i]=polynomial1[i];
            i++;
            temp--;
        }
        while(i<m){
            sum[i]=polynomial1[i]+polynomial2[j];
            i++;
            j++;
        }
        printf("The coefficients of the sum are:\n");
        for(counter=0;counter<m;counter++)
            printf("%d ", sum[counter]);
    }
    else if(n>m){
        i=0;
        j=0;
        temp=n;
        while(temp>m){
            sum[j]=polynomial2[j];
            j++;
            temp--;
        }
        while(j<n){
            sum[j]=polynomial2[j]+polynomial1[i];
            i++;
            j++;
        }
        printf("The coefficients of the sum are:\n");
        for(counter=0;counter<n;counter++)
            printf("%d ", sum[counter]);
    }
    else{
        for(counter=0;counter<m;counter++)
            sum[counter]=polynomial1[counter]+polynomial2[counter];
        printf("The coefficients of the sum are:\n");
        for(counter=0;counter<m;counter++)
            printf("%d ", sum[counter]);
    }
    return 0;
}
