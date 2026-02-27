#include <stdio.h>
#include <stdlib.h>

int main(){
    //Takes an input letter, checks if it is lower or uppercase and converts to upper case if lower case.
    char letter;
    printf("Enter a letter:");
    scanf(" %c",&letter);
    if (letter >= 'a' && letter <= 'z'){
        letter = letter - 32;
        printf("The uppercase version of the letter is: %c",letter);
    }
    else if (letter >= 'A' && letter <= 'Z'){
        printf("The letter is already uppercase: %c",letter);
    }
    else{
        printf("Exit code 1: Not a letter error");
        return 1;
    }
    return 0;
}
