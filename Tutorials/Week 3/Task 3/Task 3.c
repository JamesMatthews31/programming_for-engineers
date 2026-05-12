/*
Filename: Task 3.c
Description: Write a program that picks a random number between 1 and 100. It then prompts
the user to guess the number. If the guess is correct, print a congratulatory message.
Otherwise, tell the user if their guess was too high or too low. The user has a maximum of 3
guesses.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Picks random number between 0 and 100
    srand(time(NULL));
    int guess = 0;
    int randNum = rand()%100 + 1;
    printf("%d",randNum);
    printf("Enter guess for the number:");
    scanf("%d",&guess);
    // Same logic is reused in each attempt. User guesses, answer is compared, and a prompt to help the user guess the number is printed if incorrect.
    if (guess == randNum){
        printf("Correct answer, well done!");
    }
    else if (guess > randNum){
        printf("Too high!");
        printf("Enter guess for the number:");
        scanf("%d",&guess);
        if (guess == randNum){
            printf("Correct answer, well done!");
        }
        else if(guess > randNum){
            printf("Too high!");
            printf("Enter guess for the number:");
            scanf("%d",&guess);
            if (guess == randNum){
                printf("Correct answer, well done!");
            }
            else{
                printf("Incorrect the correct number was %d",randNum);
            }
        }
        else{
            printf("Too low!");
            printf("Enter guess for the number:");
            scanf("%d",&guess);
            if (guess == randNum){
                printf("Correct answer, well done!");
            }
            else{
                printf("Incorrect the correct number was %d",randNum);
            }
        }
    }
    else{
        printf("Too low!");
        printf("Enter guess for the number:");
        scanf("%d",&guess);
        if (guess == randNum){
            printf("Correct answer, well done!");
        }
        else if(guess > randNum){
            printf("Too high!");
            printf("Enter guess for the number:");
            scanf("%d",&guess);
            if (guess == randNum){
                printf("Correct answer, well done!");
            }
            else{
                printf("Incorrect the correct number was %d",randNum);
            }
        }
        else{
            printf("Too low!");
            printf("Enter guess for the number:");
            scanf("%d",&guess);
            if (guess == randNum){
                printf("Correct answer, well done!");
            }
            else{
                printf("Incorrect the correct number was %d",randNum);
            }
        }
    }
    return 0;
}