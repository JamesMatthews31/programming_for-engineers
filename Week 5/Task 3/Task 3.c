#include <stdio.h>

double calcCircumference(double radius);
double calcArea(double radius);

int main(){
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    printf("Circumference: %.2lf\n", calcCircumference(radius));
    printf("Area: %.2lf\n", calcArea(radius));
    return 0; 
}

double calcCircumference(double radius){
    double circumference = 2 * 3.14159 * radius;
    return circumference;
}

double calcArea(double radius){
    double area = 3.14159 * radius * radius;
    return area;
}

