#include <stdio.h>

void Figure1(int n, int key);
void Figure2(int n, int key);

int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    Figure1(n,n);
    printf("\n");
    Figure2(2,n);
    return 0;
}

void Figure1(int n, int key){
    int i;
    if(n==1){
        printf("%d ", n);
        return;
    }
    for(i=n;i<=key;i++){
        printf("%d ", i);
    }
    printf("\n");
    Figure1(n-1,key);
    printf("%d ", n);
}

void Figure2(int n, int key){
    int i;
    if(n==key){
        printf("%d\n", n);
        return;
    }
    for(i=n;i<=key;i++){
        printf("%d ", i);
    }
    printf("\n");
    Figure2(n+1,key);
}
