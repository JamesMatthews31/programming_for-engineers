/*
Filename: Task 8.c
Description: Write a program that takes a single character as input. It should test if the
character is already uppercase. If it is not, it must convert the character to uppercase. Display
the final character.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    char letter;
    printf("Enter a letter:");
    scanf(" %c",&letter);
    // Checks if letter is lowercase, if it is makes it uppercase by adding 32 to change its value in ASCII
    if (letter >= 'a' && letter <= 'z'){
        letter = letter - 32;
        printf("The letter in uppercase: %c",letter);
    }
    // Checks if letter is uppercase
    else if (letter >= 'A' && letter <= 'Z'){
        printf("The letter is already uppercase: %c",letter);
    }
    // Case if the input is not a letter
    else{
        printf("Exit code 1: input is not a letter");
        return 1;
    }
    return 0;
}
