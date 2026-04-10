/*
Filename: Task 4.c
Description: 

Define a structure type Person_Name to contain the parts of a person’s name including the
following:

    i) first_name a character array (string) of length LEN
    ii) initial a single character
    iii) second_name a character array (string) of length LEN

Using the Person_Name structure type, create a larger structure type Student which contains
the following:

    i) name type Person_name
    ii) id_number and age both integers
    iii) module code a character array of suitable length

Create an array of structures of type Student and write functions to

    (a) read in an individual student’s data
    (b) display an individual student’s data
    (c) display the complete list (array) of data stored for all students as a table


Author: James Matthews
Date: 10/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#define LEN 50

// Structures

typedef struct{
    char firstName[LEN];
    char initial;
    char secondName[LEN];
} personName;

typedef struct{
    personName name;
    int idNumber;
    int age;
    char moduleCode[10];
} student;

// Function prototypes

student createStudent();
void displayStudent(student s);
void displayAllStudents(student students[], int size);


// Main

int main(){
    student students[2];
    for (int i = 0; i < 2; i++){
        students[i] = readStudent();
        printf("Student created.\n");
    }
    
}

// Functions

student readStudent(){
    student s;
    printf("Enter first name: ");
    scanf("%s", &s.name.firstName);
    printf("Enter initial: ");
    scanf(" %c", &s.name.initial);
    printf("Enter second name: ");
    scanf("%s", &s.name.secondName);
    printf("Enter ID number: ");
    scanf("%d", &s.idNumber);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter module code: ");
    scanf("%s", &s.moduleCode);
    return s;
}

void displayStudent(student s){
    printf("Name: %s %c %s\n", s.name.firstName, s.name.initial, s.name.secondName);
    printf("ID Number: %d\n", s.idNumber);
    printf("Age: %d\n", s.age);
    printf("Module Code: %s\n", s.moduleCode);
}
