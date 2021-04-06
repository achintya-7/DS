#include<math.h>

#include<stdio.h>


#define Pi 3.14159
int main()
{
    double sine, rad, deg;
    scanf("%lf", &deg);
    rad = deg * Pi / 180;
    sine = sin(rad);

    printf("\n %lf is sine value", sine);

}
