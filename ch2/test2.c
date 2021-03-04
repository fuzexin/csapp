#include<stdio.h>

void main(){

    int x = 0x80000000;
    if((x-1)<0)
        printf("True");
    else
        printf("False");

}