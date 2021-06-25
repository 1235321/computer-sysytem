#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("\x1b[H\x1b[2J");
    return 0;
}