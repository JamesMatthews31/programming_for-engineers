/*
Filename: Task 1.c
Description: Write a program that asks the user to input 4 numbers and displays the minimum
value.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
 int main(){
    float num1,num2,num3,num4 = 0;
    // Take number input
    printf("Enter number 1:");
    scanf("%f",&num1);
    // Set first number input as min
    float min = num1;
    printf("Enter number 2:");
    scanf("%f",&num2);
    // Check if next number is smaller, assign to min if it is.
    if(num2 < min){
        min = num2;
    }
    printf("Enter number 3:");
    scanf("%f",&num3);
    // Check if next number is smaller, assign to min if it is.
    if(num3 < min){
        min = num3;
    }
    printf("Enter number 4:");
    scanf("%f",&num4);
    // Check if next number is smaller, assign to min if it is.
    if(num4 < min){
        min = num4;
    }
    // Return min value.
    printf("The minimum value is: %.4f\n",min);
    return 0;
    // Works by checking each number against the current minimum value and updating the minimum value to the new number if it is smaller.
 }