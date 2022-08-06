#include <stdio.h>

int main(){
    int products_sold, product_no, counter=0;
    float sum=0.0;
    printf("Enter the amount of products sold\n") ;
    scanf("%d", &products_sold);
    while(counter<products_sold){
        printf("Enter the product number sold\n");
        scanf("%d", &product_no);
        switch(product_no){
            case 1: sum+=50.5; break;
            case 2: sum+=45.6; break;
            case 3: sum+=32.8; break;
            case 4: sum+=65.3; break;
            case 5: sum+=20.0; break;
            default: printf("The product doesn't exist\n"); break;
        }
        counter++;
    }
    printf("The total amount of products sold is %d for an amount of %.2f\n", products_sold, sum);
    return 0;
}
