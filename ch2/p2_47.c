/*
 
 */
#include<stdio.h>
#include<string.h>

void main()
{
    float a = 0.06;
    unsigned char c[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    memcpy(c, &a, 8);
    for (size_t i = 0; i < 8; i++)
    {
        printf("%x\n", c[i]);
    }
    
}