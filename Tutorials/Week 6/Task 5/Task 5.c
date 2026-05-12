/*
Filename: Task 5.c
Description: Copy and paste the program below into a CLion project. The function readarray(int A[], int
n) reads values into an array from the user. Read this function carefully and make sure you
understand the syntax.

Write a similar function, printarray(), which prints the array elements. Test that both
functions are working by calling them from main().

Author: James Matthews
Date: 08/03/2026
Version: 1.0
Log:
*/


#include <stdio.h>
#define ARRAYSIZE 10

int arr1[ARRAYSIZE], arr2[ARRAYSIZE], arr3[ARRAYSIZE];

// Function bodies

void readArray(int A[], int n) {
    // Asks user to type out 10 numbers then iterates through them to fill the array.
    int i;
    printf("Enter %d integers (separated by spaces) into array: ", n);
    for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
}

void printArray(int A[], int n) {
    // Iterates through the array and prints each element.
    int i;
    printf("Array elements: ");
    for (i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main(void) {
    readArray(arr1, ARRAYSIZE);
    readArray(arr2, ARRAYSIZE);
    readArray(arr3, ARRAYSIZE);
    printArray(arr1, ARRAYSIZE);
    printArray(arr2, ARRAYSIZE);
    printArray(arr3, ARRAYSIZE);
    return 0;
}
