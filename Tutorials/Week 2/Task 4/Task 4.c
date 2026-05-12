/*
Filename: Task 2.c
Description: You are designing a right-angled support bracket. You need a quick way to
calculate its perimeter and area to ensure it meets material specifications.
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#include <math.h>

int main(void){
    float height = 0;
    float length = 0;
    float hyp = 0;
    float area = 0;
    float perimeter = 0;
    // Collect values of triangle to use in calculations.
    printf("Please enter the height of the triangle: ");
    scanf("%f", &height);
    printf("Please enter the length of the triangle: ");
    scanf("%f", &length);
    // Carry out calculations.
    hyp = sqrt((height * height) + (length * length));
    area = height * length * 0.5;
    perimeter = height + length + hyp;
    // Print calculated values.
    printf("The area of the triangle is: %.4f\n", area);
    printf("The perimeter of the triangle is: %.4f\n", perimeter);
}