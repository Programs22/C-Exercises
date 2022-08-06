#include <stdio.h>

#define size 100

int main(){
    int array[size];
    int counter, n;
    printf("Enter the length of the array\n");
    scanf("%d", &n);
    for(counter=0;counter<n;counter++){
        printf("Enter an element in the array\n");
        scanf("%d", &array[counter]);
    }
    for(counter=0;counter<n;counter++){
        while(array[counter]<array[counter+1]&&counter<n-1){
            printf("%d ", array[counter]);
            counter++;
        }
        printf("%d\n", array[counter]);
    }
    return 0;
}
