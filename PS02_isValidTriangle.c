#include <stdio.h>

int isValidTriangle(double side1, double side2, double side3)
{
    if (side1 + side2 <= side3) return 0;
    if (side2 + side3 <= side1) return 0;
    if (side3 + side1 <= side2) return 0;
    return 1;
}

int main()
{
    double side1, side2, side3;
    printf("Enter all three sides of a triangle: ");
    printf(isValidTriangle(side1, side2, side3) ? "valid" : "invalid");
    return 0;
}