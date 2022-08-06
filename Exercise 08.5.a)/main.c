#include <stdio.h>

#define size 100

void selectionSort(int a[], int n);

int main(){
    int array[size];
    int counter, n; // n is the array dimension
    printf("Enter the dimension of the array\n");
    scanf("%d", &n);
    for(counter=0;counter<n;counter++){
        printf("Enter a number in the array\n");
        scanf("%d", &array[counter]);
    }
    selectionSort(array,n);
    for(counter=0;counter<n;counter++)
        printf("%d ", array[counter]);
    return 0;
}

void selectionSort(int a[], int n){ // Selection sort is similar to bubble sort because it always goes through the whole array in order to find the remaining minimal element
    int i, j, min; // Counters for the subsequent for loops
    for(i=0;i<n-1;i++){
        min=a[i];
        for(j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                a[j]=a[i];
                a[i]=min;
            }
        }
    }
}
