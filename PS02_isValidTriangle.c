#include <stdio.h>

int isValidTriangle(double side1, double side2, double side3)
{
    if (side1 + side2 <= side3) return 0;
    if (side2 + side3 <= side1) return 0;
    if (side3 + side1 <= side2) return 0;
    return 1;
}

char* typeOfTriangle(double side1, double side2, double side3){
    if(side1 == side2 && side2 == side3) return "equilateral";
    if(side1 == side2 || side2 == side3 || side1 == side3) return "isosceles";

    return "scalene";
}

int main()
{
    double side1, side2, side3;
    printf("Enter all three sides of a triangle: ");
    scanf("%lf %lf %lf", &side1, &side2, &side3);

    if(isValidTriangle(side1, side2, side3)){
        printf("%s", typeOfTriangle(side1, side2, side3));
    }
    else{
        printf("Invalid triangle");
    }
    return 0;
}