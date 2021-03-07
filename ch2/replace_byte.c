#include<stdio.h>
#include<stdlib.h>

unsigned replace_byte(unsigned x, int i, unsigned char b);
unsigned short checkIsLittleEndian();
unsigned short checkIsLittleEndian()
{
    int test_int = 0x01;
    unsigned char* ptr = (char*)&test_int;
    if (((int)*(ptr) == 0x01))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    system("pause");
    return 0;
}
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if(!(0<=i && i<sizeof(unsigned)))
        return 0;
    unsigned char* ptr = (char*)&x;
    if (checkIsLittleEndian())
    {
        *(ptr+i) = b;
    }
    else
    {
        *(ptr+sizeof(unsigned)-1-i) = b;
    }
    return x;
    
}

int main()
{
    unsigned x = replace_byte(0x12345678, 10, 0xAB);
    unsigned y = replace_byte(0x12345678, 0, 0xAB);
    printf("%X\n", x);
    printf("%X\n", y);
    system("pause");
    return 0;
}