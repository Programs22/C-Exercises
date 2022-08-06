#include <stdio.h>
#include <math.h>

int main(){
    double amount, principal=1000.0, rate=0.05;
    int year;
    printf("%4s %-25s\n", "Year", "Deposit amount");
    for(year=1;year<=10;year++){
        amount=principal*pow(1.0+rate,year);
        printf("%4d %-25.2f\n", year, amount);
    }
    return 0;
}
