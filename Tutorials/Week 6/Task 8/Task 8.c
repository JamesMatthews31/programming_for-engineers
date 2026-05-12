/*
Filename: Task 8.c
Description: 

See the program below. Run it. The function swap_nums() seems to work, but the function
swap_pointers() does not. Modify the program so that swap_pointers() works correctly.

Author: James Matthews
Date: 08/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>

void swap_nums(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_pointers(char **x, char **y){
    char **tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    int a, b;
    char *s1, *s2;
    a = 3; b = 4;
    swap_nums(&a, &b);
    printf("a is %d\n", a);
    printf("b is %d\n", b);
    s1 = "I should print second";
    s2 = "I should print first";
    swap_pointers(&s1, &s2);
    printf("s1 is %s\n", s1);
    printf("s2 is %s\n", s2);
    return 0;
}

// The error was that the arguments passed into swap_pointers were just pointer, but needed to be pointers to pointers, so adding another * fixed this, alongside adding * to all x,y and tmp. 
// Also made the function call pass addresses