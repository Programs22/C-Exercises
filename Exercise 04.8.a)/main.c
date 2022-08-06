#include <stdio.h>

int main(){
    int product;
    printf("Enter the product number\n");
    scanf("%d", &product);
    switch(product){
        case 1: printf("The price of product %d is 50.5\n", product); break;
        case 2: printf("The price of product %d is 45.6\n", product); break;
        case 3: printf("The price of product %d is 32.8\n", product); break;
        case 4: printf("The price of product %d is 65.3\n", product); break;
        case 5: printf("The price of product %d is 20.0\n", product); break;
        default: printf("Product doesn't exist in the shop\n"); break;
    }
    return 0;
}
