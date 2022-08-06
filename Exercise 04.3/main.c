#include <stdio.h>

int main(){
    int counter, grade, total=0, i=0;
    float average;
    printf("Enter how many students are in the class\n");
    scanf("%d", &counter);
    while(i<counter){
        printf("Enter a grade\n");
        scanf("%d", &grade);
        total+=grade;
        i++;
    }
    average=(float)total/counter;
    printf("The average of the class is %.3f\n", average);
    return 0;
}