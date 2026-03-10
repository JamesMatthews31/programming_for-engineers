/*
Filename: Task 4.c
Description: 

Write a function called is_even that:
1. Takes one integer as input.
2. Returns 1 (true) if the number is even.
3. Returns 0 (false) if the number is odd.
4. Use this function in main() to print "Even" or "Odd".

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

// Function prototype

int isEven(int number);


void main(){
    // Ask user to enter input then check if even
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    switch (isEven(num)){
        case 0:
            printf("%d is odd.\n", num);
            break;
        case 1:
            printf("%d is even.\n", num);
            break;
        case 2:
            printf("The number is zero.\n");
            break;
    }
}

// Function body

int isEven(int a){
    // Returns value 0-2 based on even, odd or zero
    if (a == 0){
        return 2;
    }
    if (a % 2 == 0){
        return 1;
    }
    else {
        return 0;
    }
}