/*
Filename: Task 5.c
Description:

Write a function called power (base, exponent) that calculates base^exponent without using
the <math.h> library.
1. Use a loop inside the function.
2. Assume the exponent is a positive integer.
3. Return the result.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

// Function prototype

float power(float base, unsigned int exponent);

int main(){
    // Collects values for base and exponent
    float base;
    unsigned int exponent;
    printf("Enter the base for the calculation: ");
    scanf("%f", &base);
    printf("Enter the exponent for the calculation: ");
    scanf("%u", &exponent);
    printf("The calculation gives: %f\n", power(base, exponent));
    return 0;
}

// Function body

float power(float base, unsigned int exponent){
    float output = 1;
    // Multiplies the base by itelf based on exponent.
    for (int i = 0; i < exponent; i++){
        output *= base;
    }
    return output;
}