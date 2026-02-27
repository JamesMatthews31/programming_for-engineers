#include <stdio.h>
#include <stdlib.h>

int main(){
    char dataPacket[] = {'P','A','C','K','E','T'};
    for (int i = 5; i >= 0; i--){
        printf("%c", dataPacket[i]);
    }
}