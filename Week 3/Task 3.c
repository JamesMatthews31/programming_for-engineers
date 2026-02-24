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