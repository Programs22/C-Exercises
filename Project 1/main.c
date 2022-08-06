#include <stdio.h>

#define size 100

float average(int a[], int n);
void sort(int a[], int n);
float median(int a[], int n);
void Histogram(int a[], int n);
int mostFrequent(int a[], int n);

int main(){
    int array[size];
    int counter, n;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    for(counter=0;counter<n;counter++){
        printf("Enter an element of the array\n");
        scanf("%d", &array[counter]);
    }
    Histogram(array,n);
    printf("The average of all the elements in the array is %.3f\n", average(array,n));
    printf("The most frequent element in the array is %d\n", mostFrequent(array,n));
    sort(array,n);
    for(counter=0;counter<n;counter++)
        printf("%d ", array[counter]);
    printf("\nThe median of the array is %.3f\n", median(array,n));
    return 0;
}

float average(int a[], int n){
    int counter, sum=0;
    for(counter=0;counter<n;counter++)
        sum+=a[counter];
    return (float)sum/n;
}

void sort(int a[], int n){
    int i, j, min; // Counters i and j for the subsequent for loops
    for(i=0;i<n-1;i++){
        min=a[i];
        for(j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                a[j]=a[i];
                a[i]=min;
            }
        }
    }
}

float median(int a[], int n){
    float median;
    if(n%2==0)
        median=(a[n/2]+a[n/2-1])/2.;
    else
        median=a[n/2];
    return median;
}

void Histogram(int a[], int n){
    int i, j; // Counters for the subsequent for loops
    printf("%s%12s%13s\n", "Position", "Value", "Histogram");
    for(i=0;i<n;i++){
        printf("%8d%12d    ", i, a[i]);
        for(j=0;j<a[i];j++)
            printf("%c", '*');
        printf("\n");
    }
}

int mostFrequent(int a[], int n){
    int i, j, max=0, value=a[0], count; // i and j are counters for the for loops
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(a[j]==a[i])
                count++;
        }
        if(max<count){
            max=count;
            value=a[i];
        }
    }
    return value;
}
