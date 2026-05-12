/*
Filename: Task 2.c
Description: 

Write a function called add_numbers that:
1. Takes two integers as input arguments.
2. Returns their sum as an integer.
3. In main(), ask the user for two numbers, call your function, and print the result

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

// Function prototype

int addNumbers(int a, int b);

// Function body

int addNumbers(int a, int b){
    return a + b;
}

int main(){
    // Collects number to be added then returns.
    int num1, num2;
    printf("Enter the first number to be added: ");
    scanf("%d", &num1);
    printf("Enter the second number to be added: ");
    scanf("%d", &num2);
    printf("Sum of 2 numbers: %d\n", addNumbers(num1, num2));
    return 0;
}

