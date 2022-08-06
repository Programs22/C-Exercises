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
    for(counter=1;counter<n;counter++){
        if(array[counter]<array[counter+1]&&array[counter]>array[counter-1]&&counter<n-1){
            printf("%d %d ", array[counter-1], array[counter]);
            counter++;
            printf("%d ", array[counter]);
            while(array[counter]<array[counter+1]&&counter<n-1){
                counter++;
                printf("%d ", array[counter]);
            }
        }
        printf("\n");
    }
    return 0;
}
