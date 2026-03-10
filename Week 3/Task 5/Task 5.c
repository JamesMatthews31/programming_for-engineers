/*
Filename: Task 5.c
Description: Write a program that takes a user's input. If it's between -10 and 10, it should
output (a) whether the value is positive, negative, or zero, and (b) whether it is odd or even. If
the input is outside the range, it should print an error message.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>


int main(){
    printf("Enter a number between -10 and 10:");
    int num;
    scanf("%d",&num);
    // Checks if number is in range
    if (num < -10 || num > 10){
        printf("Exit code 1: Out of range error");
        return 1;
    }
    // Checks if number is negative
    else if (num < 0){
        printf("Negative number,");
        // Checks if number is odd or even
        if (num % 2 == 0){
            printf(" Even");
        }
        else{
            printf(" Odd");
        }
    }
    // Checks if number is positive
    else if (num > 0){
        printf("Positive number,");
        // Checks if number is odd or even
        if (num % 2 == 0){
            printf(" Even");
        }
        else{
            printf(" Odd");
        }
    }
    // Will return zero if not positive or negative
    else{
        printf("Zero");
    }
}