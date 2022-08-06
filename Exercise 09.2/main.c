#include <stdio.h>

int main(){
    int array[12], delta_x, delta_y, delta_z, delta, counter=0;
    float x, y, z;
    printf("Enter the coefficients of the first equation\n");
    while(counter<4){
        scanf("%d", &array[counter]);
        counter++;
    }
    printf("Enter the coefficients of the second equation\n");
    while(counter<8){
        scanf("%d", &array[counter]);
        counter++;
    }
    printf("Enter the coefficients of the third equation\n");
    while(counter<12){
        scanf("%d", &array[counter]);
        counter++;
    }
    delta=(array[0]*array[5]*array[10])+(array[1]*array[6]*array[8])+(array[2]*array[4]*array[9])-(array[2]*array[5]*array[8])-(array[0]*array[6]*array[9])-(array[1]*array[4]*array[10]);
    delta_x=(array[3]*array[5]*array[10])+(array[1]*array[6]*array[11])+(array[2]*array[7]*array[9])-(array[2]*array[5]*array[11])-(array[3]*array[6]*array[9])-(array[1]*array[7]*array[10]);
    delta_y=(array[0]*array[7]*array[10])+(array[3]*array[6]*array[8])+(array[2]*array[4]*array[11])-(array[2]*array[7]*array[8])-(array[0]*array[6]*array[11])-(array[3]*array[4]*array[10]);
    delta_z=(array[0]*array[5]*array[11])+(array[1]*array[7]*array[8])+(array[3]*array[4]*array[9])-(array[3]*array[5]*array[8])-(array[0]*array[7]*array[9])-(array[1]*array[4]*array[11]);
    x=(float)delta_x/delta;
    y=(float)delta_y/delta;
    z=(float)delta_z/delta;
    printf("The solution to the equation is: x=%.3f y=%.3f z=%.3f\n", x, y, z);
    return 0;
}
