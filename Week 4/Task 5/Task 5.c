/*
Filename: Task 5.c
Description: 

1. Create an array of 6 chars and initialize it with any characters you like (e.g., {'P', 'A', 'C', 'K', 'E', 'T'}).
2. Use a for loop to print the array elements in reverse order.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    char dataPacket[] = {'P','A','C','K','E','T'};
    // Iterates through the list in reverse order to print the string backwards.
    for (int i = 5; i >= 0; i--){
        printf("%c", dataPacket[i]);
    }
}