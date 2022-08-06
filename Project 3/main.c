#include <stdio.h>

#define size 100

void printGrades(int grades[][5], int n);
void minimalGrade(int grades[][5], int n);
void maximalGrade(int grades[][5], int n);
void averageGrade(int grades[][5], int n);

int main(){
    void (*functions[4])(int grades[][5], int n)={printGrades, minimalGrade, maximalGrade, averageGrade};
    int grades[size][5];
    int i, j, n, choice; // Counters i and j for the subsequent for loops
    printf("Enter how many students are in the class\n");
    scanf("%d", &n);
    printf("Enter the grades for each student\n");
    for(i=0;i<n;i++){
        printf("Student %d\n", i+1);
        for(j=0;j<5;j++){
            printf("Enter a grade\n");
            scanf("%d", &grades[i][j]);
        }
    }
    printf("Enter a number between 0 and 3 to choose from the available functions, enter 4 to end\n");
    scanf("%d", &choice);
    while(choice>=0&&choice<4){
        (*functions[choice])(grades, n);
        printf("Enter a number between 0 and 3 to choose from the available functions, enter 4 to end\n");
        scanf("%d", &choice);
    }
    printf("End of program\n");
    return 0;
}

void printGrades(int grades[][5], int n){
    int i, j;
    for(i=0;i<n;i++){
        printf("Grades for student %d: ", i+1);
        for(j=0;j<5;j++)
            printf("%d ", grades[i][j]);
        printf("\n");
    }
}

void minimalGrade(int grades[][5], int n){
    int i, j, min=6;
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            if(min>grades[i][j])
                min=grades[i][j];
        }
    }
    printf("The minimal grade in the class is %d\n", min);
}

void maximalGrade(int grades[][5], int n){
    int i, j, max=0;
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            if(max<grades[i][j])
                max=grades[i][j];
        }
    }
    printf("The maximal grade in the class is %d\n", max);
}

void averageGrade(int grades[][5], int n){
    int i, j, sum;
    float average;
    for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<5;j++){
            sum+=grades[i][j];
        }
        average=(float)sum/5;
        printf("The average grade of student %d is %f\n", i+1, average);
    }
}
