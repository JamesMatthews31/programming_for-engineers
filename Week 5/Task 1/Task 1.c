/*
Filename: Task 1.c
Description: Write a function called print_welcome_message() that takes no arguments and returns
nothing (void).
Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
// Function prototype
void printWelcomeMessage(void);
// Function body
void printWelcomeMessage(void){
    printf("****************************************\n*     ENGINEERING CALCULATOR v1.0      *\n*     System Ready. Awaiting Input.    *\n****************************************\n");
}

int main(){
    // Function call
    printWelcomeMessage();
    return 0;   
}