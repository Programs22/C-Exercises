#include <stdio.h>

#define size 100

void enterMatrix(int m, int n, int matrix[size][size]);
void printMatrix(int m, int n, int matrix[size][size]);

int main(){
    int matrix[size][size];
    int m, n; // m and n are the variables for the rows and columns in the matrix
    printf("Enter the dimensions of the matrix\n");
    scanf("%d%d", &m, &n);
    enterMatrix(m,n,matrix);
    printMatrix(m,n,matrix);
    return 0;
}

void enterMatrix(int m, int n, int matrix[size][size]){
    int i, j; // Counters for the subsequent for loops
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            printf("Enter a number in the matrix\n");
            scanf("%d", &matrix[i][j]);
        }
}

void printMatrix(int m, int n, int matrix[size][size]){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
