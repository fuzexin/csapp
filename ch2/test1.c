#include<stdio.h>

void main(){
    float f_n = 0.1;
    char* header = &f_n;
    printf("%d\n", sizeof(f_n));
}