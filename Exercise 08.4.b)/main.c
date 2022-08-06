#include <stdio.h>

#define size 100

void enterMatrix(int m, int n, int matrix[size][size]);
void printMatrix(int m, int n, int matrix[size][size]);

int main(){
    int matrix[size][size];
    int m, n;
    printf("Enter the matrix dimensions\n");
    scanf("%d%d", &m, &n);
    enterMatrix(m,n,matrix);
    printMatrix(m,n,matrix);
    return 0;
}

void enterMatrix(int m, int n, int matrix[size][size]){
    int temp=n;
    if(m==0)
        return;
    while(n>0){
        printf("Enter a number in the matrix\n");
        scanf("%d", &matrix[m-1][n-1]);
        n--;
    }
    enterMatrix(m-1,temp,matrix);
}

void printMatrix(int m, int n, int matrix[size][size]){
    int temp=n;
    if(m==0)
        return;
    while(n>0){
        printf("%d ", matrix[m-1][n-1]);
        n--;
    }
    printf("\n");
    printMatrix(m-1,temp,matrix);
}
