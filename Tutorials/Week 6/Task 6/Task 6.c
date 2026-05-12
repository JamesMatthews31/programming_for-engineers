/*
Filename: Task 6.c
Description: Write a function that takes two arrays (representing vectors) and their size as parameters, and
returns their dot product
Author: James Matthews
Date: 08/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#define ARRAYSIZE 5

// Function prototype

double dotProduct(int A[], int B[], int n);


int main(void){
    int vector1[ARRAYSIZE], vector2[ARRAYSIZE];
    // Collects values 
    printf("Enter %d integers (separated by spaces) into first vector: ", ARRAYSIZE);
    for (int i = 0; i < ARRAYSIZE; i++){
        scanf("%d", &vector1[i]);
    }
    printf("Enter %d integers (separated by spaces) into second vector: ", ARRAYSIZE);
    for (int i = 0; i < ARRAYSIZE; i++){
        scanf("%d", &vector2[i]);
    }
    printf("The dot product of the two vectors is: %.4lf\n", dotProduct(vector1, vector2, ARRAYSIZE));
    return 0;
}

// Function body

double dotProduct(int A[], int B[], int n){
    // Calculates dot product using for loop to iterate through arrays.
    double calcValue = 0;
    for (int i = 0; i < n; i++){
        calcValue += A[i] * B[i];
    }
    return calcValue;
}