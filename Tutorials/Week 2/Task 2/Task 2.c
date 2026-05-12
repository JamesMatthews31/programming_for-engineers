/*
Filename: Task 2.c
Description: A data packet from a legacy system has its bytes reversed. You need to write a
program to correct it. The packet is represented as a two-digit number.
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(void){
    // numIn is a two digit number such that its form is digit1digit2. swappedNum is hence digit2digit1.
    int digit1 = 0;
    int digit2 = 0;
    int numIn = 0;
    int swappedNum = 0;
    printf("Please enter number: ");
    scanf("%d", &numIn);
    // Mathematical operations to swap digits
    digit1 = numIn / 10;
    digit2 = numIn % 10;
    swappedNum = (digit2*10) + digit1;
    printf("The swapped number is: %d\n", swappedNum);
}