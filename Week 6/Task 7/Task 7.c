/*
Filename: Task 7.c
Description: 

Write a function that performs a “crossover” of two “parent” arrays p1[] and p2[] to produce
two “offspring” arrays c1[] and c2[]. The function should take all four arrays, the array size n,
and a crosspoint k as parameters.

Crossover operates as follows:
• c1[] contains elements 0..k-1 from p1[] and elements k..n-1 from p2[].
• c2[] contains elements 0..k-1 from p2[] and elements k..n-1 from p1[].

Author: James Matthews
Date: 08/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#define ARRAYSIZE 10

// Function prototype

void crossover(int p1[], int p2[], int c1[], int c2[], int n, int k);
void readArray(int A[], int n);
void printArray(int A[], int n);

void crossover(int p1[], int p2[], int c1[], int c2[], int n, int k) {
    int i;
    for (i = 0; i < k; i++){
        c1[i] = p1[i];
        c2[i] = p2[i];
    }
    for (i = k; i < n; i++){
        c1[i] = p2[i];
        c2[i] = p1[i];
    }
}

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

int main(void){
    // Collect values for arrays and crossover point then prints outcomes
    int parent1[ARRAYSIZE], parent2[ARRAYSIZE], child1[ARRAYSIZE], child2[ARRAYSIZE];
    int crosspoint;
    printf("Enter the point to cross over between 0 and %d: ", ARRAYSIZE);
    scanf("%d", &crosspoint);
    readArray(parent1, ARRAYSIZE);
    readArray(parent2, ARRAYSIZE);
    crossover(parent1, parent2, child1, child2, ARRAYSIZE, crosspoint);
    printArray(child1, ARRAYSIZE);
    printArray(child2, ARRAYSIZE);
    return 0;
}
// 11 12 13 14 15 16 17 18 19 20
// 1 2 3 4 5 6 7 8 9 10
