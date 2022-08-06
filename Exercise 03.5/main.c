#include <stdio.h>

int main(){
    float radius, pi=3.14;
    printf("Enter the radius of the circle\n");
    scanf("%f", &radius);
    printf("The perimeter and area of a circle with a radius of %f are %f and %f", radius, 2*radius*pi, radius*radius*pi);
    return 0;
}
