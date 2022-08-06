#include <stdio.h>
#include <math.h>

int main(){
    int n; // n is the number of sides in the polygon
    float side, angle, apothem, perimeter, area;
    printf("Enter the numbers of sides in the polygon\n");
    scanf("%d", &n);
    printf("Enter the length of the side of the polygon\n");
    scanf("%f", &side);
    angle=360/n;
    angle=angle*3.14/180;
    apothem=side/(2*tan(angle/2));
    perimeter=n*side;
    area=(n*side*apothem)/2;
    printf("The perimeter and area of a polygon with %d sides are %f and %f\n", n, perimeter, area);
    return 0;
}
