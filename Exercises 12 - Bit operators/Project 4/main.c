#include <stdio.h>
#include <string.h>

#define size 20

typedef struct employee{
    int ID;
    char Name[size];
    char Surname[size];
    int Age;
    char Gender;
    int Marriage; // 0 if not married, 1 if married
    int Credibility; // Number between 0-100
    char Address[70];
    int currentWage;
    int previousWage;
}Employee;

void sortCredibility(Employee E[], int n);
void sortCurrentWage(Employee E[], int n);
void sortPreviousWage(Employee E[], int n);
void setEmployee(Employee E[], int n);
void correctCredibility(Employee E[], int n);

int main(){
    Employee employees[50];
    int n, i, choice; // Counter i for the for loop
    void (*functions[5])(Employee E[], int n)={sortCredibility, sortCurrentWage, sortPreviousWage, setEmployee, correctCredibility};
    printf("Enter how many employees are in the company\n");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the ID of the employee\n");
        scanf("%d", &employees[i].ID);
        printf("Enter the name and surname of the employee\n");
        scanf(" %s", &employees[i].Name);
        scanf(" %s", &employees[i].Surname);
        printf("Enter the age of the employee\n");
        scanf("%d", &employees[i].Age);
        printf("Enter the gender of the employee\n");
        scanf(" %c", &employees[i].Gender);
        printf("Enter a value whether the employee is married or not, and then enter their credibility\n");
        scanf("%d%d", &employees[i].Marriage, &employees[i].Credibility);
        printf("Enter the address of the employee\n");
        scanf(" %s", &employees[i].Address);
        printf("Enter the current and previous wage of the employee\n");
        scanf("%d%d", &employees[i].currentWage, &employees[i].previousWage);
    }
    printf("Enter a number between 0 and 4 for which function you want to do\n");
    printf("0 - Sort employees by credibility\n");
    printf("1 - Sort employees by current wage\n");
    printf("2 - Sort employees by previous wage\n");
    printf("3 - Set employee data\n");
    printf("4 - Correct employee credibility\n");
    scanf("%d", &choice);
    (*functions[choice])(employees,n);
    for(i=0;i<n;i++)
        printf("Employee %s %s with ID number %d, current wage:%d, previous wage:%d, credibility:%d\n", employees[i].Name, employees[i].Surname, employees[i].ID, employees[i].currentWage, employees[i].previousWage, employees[i].Credibility);
    return 0;
}

void sortCredibility(Employee E[], int n){
    int i, j, min; // Counters
    Employee temp;
    for(i=0;i<n-1;i++){
        min=E[i].Credibility;
        for(j=i+1;j<n;j++){
            if(min>E[j].Credibility){
                temp=E[j];
                E[j]=E[i];
                E[i]=temp;
            }
        }
    }
}

void sortCurrentWage(Employee E[], int n){
    int i, j, min; // Counters i and j
    Employee temp;
    for(i=0;i<n-1;i++){
        min=E[i].currentWage;
        for(j=i+1;j<n;j++){
            if(min>E[j].currentWage){
                temp=E[j];
                E[j]=E[i];
                E[i]=temp;
            }
        }
    }
}

void sortPreviousWage(Employee E[], int n){
    int i, j, min; // Counters i and j
    Employee temp;
    for(i=0;i<n-1;i++){
        min=E[i].previousWage;
        for(j=i+1;j<n;j++){
            if(min>E[j].previousWage){
                temp=E[j];
                E[j]=E[i];
                E[i]=temp;
            }
        }
    }
}

void setEmployee(Employee E[], int n){
    int ID, i;
    printf("Enter an ID of an employee\n");
    scanf("%d", &ID);
    for(i=0;i<n;i++){
        if(ID==E[i].ID){
            strcpy(E[i].Name,"John");
            strcpy(E[i].Surname,"Smith");
            E[i].Age=40;
            E[i].Gender='m';
            E[i].currentWage=32000;
            E[i].previousWage=20000;
            E[i].Credibility=60;
            break;
        }
    }
}

void correctCredibility(Employee E[], int n){
    int i;
    for(i=0;i<n;i++){
        if(E[i].currentWage>E[i].previousWage){
            E[i].Credibility+=3;
            E[i].currentWage=E[i].previousWage;
        }
        else if(E[i].currentWage<E[i].previousWage){
            E[i].Credibility-=3;
            E[i].currentWage=E[i].previousWage;
        }
    }
}
