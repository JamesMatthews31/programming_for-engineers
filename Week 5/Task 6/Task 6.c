/*
Filename: Task 6.c
Description:

1. Write a function void swap(int a, int b) that attempts to swap the values of a and b using a
temporary variable.
2. Call it from main() with two variables x = 5 and y = 10.
3. Print x and y after the function call.
4. Observe: Did they swap?
5. Explain: Write a comment in your code explaining why it failed.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

// Function prototype

void swapVariables(int a, int b);

int main(){
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
    swapVariables(num1, num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}

void swapVariables(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

// This function failes because a and b passed into the functions as copies of the values of num1 and num2, so do not change the original values
// In order to fix this we need to use pointers