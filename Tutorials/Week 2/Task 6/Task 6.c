/*
Filename: Task 6.c
Description: You need to generate a random number as a base for a temporary encryption key.
The user needs to specify the upper bound for the key's value.
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    // Seed random number using time.
    srand(time(NULL));
    unsigned int maxValue = 0;
    unsigned int keyValue = 0;
    printf("Enter the maximum key value: ");
    scanf("%u", &maxValue);
    // Return value between 0 and inputted max value.
    keyValue = rand()%(maxValue + 1);
    printf("The key value is: %u\n", keyValue);
}