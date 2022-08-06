#include <stdio.h>

#define size 100

void selectionSortR(int a[], int n, int index);

int main(){
    int array[size];
    int counter, n;
    printf("Enter the array dimension\n");
    scanf("%d", &n);
    for(counter=0;counter<n;counter++){
        printf("Enter an element in the array\n");
        scanf("%d", &array[counter]);
    }
    selectionSortR(array,n,0);
    for(counter=0;counter<n;counter++)
        printf("%d ", array[counter]);
    return 0;
}

void selectionSortR(int a[], int n, int index){ // index is used for the starting index in the array
    int min=a[index];
    int j;
    if(n==index)
        return;
    for(j=index+1;j<n;j++){
        if(a[j]<min){
            min=a[j];
            a[j]=a[index];
            a[index]=min;
        }
    }
    selectionSortR(a,n,index+1);
}