/*
Filename: Task 7.c
Description: Write a program that takes a three-digit number as input and checks if it is an
Armstrong number. For example, 371 is an Armstrong number because 333 + 777 + 111 =
371.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    int num1;
    printf("Enter a 3 digit number:");
    scanf("%d",&num1);
    // Splits number into digits
    int digit1 = num1 / 100;
    int digit2 = (num1 / 10) % 10;
    int digit3 = num1 % 10;
    // Cubes digits and sums them
    int sumNum = (digit1 * digit1 * digit1) + (digit2 * digit2 * digit2) + (digit3 * digit3 * digit3);
    if (sumNum == num1){
        printf("It is an Armstrong number");
    }
    else{
        printf("It is not an Armstrong number");
    }
    return 0;
}