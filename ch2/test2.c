#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i = 100;
    if(0<=i && i<sizeof(unsigned))
        printf("0<=i<4");
    else
    {
        printf("not in range");
    }
    system("pause");
    return 0;
}