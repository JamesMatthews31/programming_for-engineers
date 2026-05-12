/*
Filename: Task 4.c
Description: Using the switch statement, write a program that converts a numerical grade into
a letter grade based on the scale: A (80-100), B (60-79), C (40-59), D (30-39), F (<30). Print
an error for inputs outside 0-100.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//

int main(){
    // Random number is seeded using time, then generates between 1 and 100
    srand(time(NULL));
    int randNum = rand()%100 + 1;
    // Prints random number so I can check if the grades are being done correctly
    printf("%d\n",randNum);
    // Switch to assign grades
    switch(randNum/10){
        case 10:
        case 9:
        case 8:
            printf("Grade: A");
            break;
        case 7:
        case 6:
            printf("Grade: B");
            break;
        case 5:
        case 4:
            printf("Grade: C");
            break;
        case 3:
            printf("Grade: D");
            break;
        case 2:
        case 1:
        case 0:
            printf("Grade: F");
            break;
        // Error code if for some reason the random number is out of range
        default:
            printf("Exit code 1: Out of range error");
            return 1;
    }
    return 0;
}