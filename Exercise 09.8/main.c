#include <stdio.h>

int main(){
    int square, cube, counter, n, i, flag; // Counter for inner for loop is i
    int digits[10];
    printf("Enter a number\n");
    scanf("%d", &n);
    for(counter=1;counter<=n;counter++){
        flag=1;
        square=counter*counter;
        cube=square*counter;
        for(i=0;i<10;i++)
            digits[i]=0;
        while(square>0){
            digits[square%10]++;
            square/=10;
        }
        while(cube>0){
            digits[cube%10]++;
            cube/=10;
        }
        for(i=0;i<10;i++){
            if(digits[i]!=1)
                flag=0;
        }
        if(flag==1)
            printf("%d meets the requirements\n", counter);
    }
    return 0;
}
