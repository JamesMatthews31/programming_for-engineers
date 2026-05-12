/*
Filename: Task 3.c
Description: 

Write two functions:
1. calculate_circumference(radius): Returns 2 * PI * r
2. calculate_area(radius): Returns PI * r^2
• Use const double PI = 3.14159;
• The radius should be a double.
• The return values should be double.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

// Function prototypes

double calcCircumference(double radius);
double calcArea(double radius);


int main(){
    // Collect radius, return area and circumference
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    printf("Circumference: %.2lf\n", calcCircumference(radius));
    printf("Area: %.2lf\n", calcArea(radius));
    return 0; 
}

// Function bodies

double calcCircumference(double radius){
    double circumference = 2 * 3.14159 * radius;
    return circumference;
}

double calcArea(double radius){
    double area = 3.14159 * radius * radius;
    return area;
}

