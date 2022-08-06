#include <stdio.h>

void Stars(int n);

int main(){
    int n;
    printf("Enter a value for n\n");
    scanf("%d", &n);
    Stars(n);
    return 0;
}

void Stars(int n){
    int counter;
    if(n==0)
        return;
    for(counter=1;counter<=n;counter++){
        printf("*");
    }
    printf("\n");
    Stars(--n);
}
