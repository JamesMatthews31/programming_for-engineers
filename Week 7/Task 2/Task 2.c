/*
Filename: Task 2.c
Description: 

Write a function which asks for a user’s date of birth and calculates how old they are in years, months, and
days. The function must use a suitable structure as input and return a struct as an output. (hint: use ctime from
time.h).

Author: James Matthews
Date: 10/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#include <time.h>

typedef struct{
    int day;
    int month;
    int year;
} date;

typedef struct{
    int years;
    int months;
    int days;
} age;

int main(){
    // Creates objects of the structures to hold dob and age
    date dateOfBirth;
    age userAge;
    // Fetches current date and fills a structure with the values
    time_t currentTime = time(NULL);
    struct tm *t = localtime(&currentTime);
    // Collects dob
    printf("Enter year of birth: ");
    scanf("%d",&dateOfBirth.year);
    printf("Enter month of birth: ");
    scanf("%d",&dateOfBirth.month);
    printf("Enter day of birth: ");
    scanf("%d",&dateOfBirth.day);
    // Calculates age
    userAge.years = t->tm_year + 1900 - dateOfBirth.year;
    userAge.months = t->tm_mon + 1 - dateOfBirth.month;
    userAge.days = t->tm_mday - dateOfBirth.day;
    if (userAge.days < 0){
        userAge.months -= 1;
        userAge.days += 30; 
    }
    if (userAge.months < 0){
        userAge.years -= 1;
        userAge.months += 12;
    }
    printf("You are %d years, %d months and %d days old.\n", userAge.years, userAge.months, userAge.days);
    }



    


    
    
