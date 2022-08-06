#include <stdio.h>

#define size 100

int main(){
    int matrix[size][size];
    int i, j, m, n, number=1; // Counters for the for loops
    printf("Enter the matrix dimensions\n");
    scanf("%d%d", &m, &n);
    for(j=0;j<n;j++){
        if(j%2==0){
            for(i=0;i<m;i++){
                matrix[i][j]=number;
                number++;
            }
        }
        else{
            for(i=m-1;i>=0;i--){
                matrix[i][j]=number;
                number++;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
