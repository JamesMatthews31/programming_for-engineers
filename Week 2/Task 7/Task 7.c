/*
Filename: Task 7.c
Description: A data stream has two values swapped. You need to write a simple algorithm to
swap them back.
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(void){
    int numA = 0;
    int numB = 0;
    int tempNum = 0;
    // Get numbers to be swapped
    printf("Enter the first number: ");
    scanf("%d", &numA);
    printf("Enter the second number: ");
    scanf("%d", &numB);
    tempNum = numA;
    numA = numB;
    numB = tempNum;
    // Print initial and swapped values
    printf("Initial values: a=%d; b=%d\n", numB, numA);
    printf("Swapped values: a=%d; b=%d\n", numA, numB);
}