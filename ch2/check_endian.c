#include<stdio.h>
#include<stdlib.h>

int main()
{
    int test_int = 0x01;
    unsigned char* ptr = (char*)&test_int;
    if (((int)*(ptr) == 0x01))
    {
        printf("LITTLE endian machine\n");
    }
    else
    {
        printf("BIG endian machine\n");
    }
    system("pause");
    return 0;
}