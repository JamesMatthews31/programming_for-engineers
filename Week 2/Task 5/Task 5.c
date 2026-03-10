/*
Filename: Task 5.c
Description: You are analyzing a signal with the formula f(x) = 3*sin(pi*x) + 2*cos(pi*x). You
need to generate a table of values to understand its behavior.
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/


#include <stdio.h>
#include <math.h>

float function(float x){
    // Function with equation to be called to calculate f(x).
    const double PI = 3.14159265;
    return (3*sin(x * PI) + 2*cos(x * PI));
}

int main(void){
    float startingValue = 0;
    float interval = 0;
    float currentX = 0;

    // Collect values for starting value and interval.

    printf("Please enter the starting value: ");
    scanf("%f", &startingValue);
    printf("Please enter the interval: ");
    scanf("%f", &interval);
    printf("Value of x\tValue of f(x)\n");

    // Loop and print values of x and f(x).

    for(int i = 0; i < 4; i++){
        currentX = startingValue + i * interval;
        printf("%-10.4f\t%.4f\n", currentX, function(currentX));
    }
}