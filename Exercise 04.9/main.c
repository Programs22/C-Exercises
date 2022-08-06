#include <stdio.h>

int main(){
    float amount, wage;
    printf("Enter the amount you've made this month, enter -1 if there are no more employees\n");
    scanf("%f", &amount);
    while(amount!=-1){
        wage=200+amount*0.09;
        printf("Your wage for this month is %.3f\n", wage);
        printf("Enter the amount you've made this month, enter -1 if there are no more employees\n");
        scanf("%f", &amount);
    }
    return 0;
}
