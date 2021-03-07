#include<stdlib.h>
#include<stdio.h>

/*declare */
unsigned short checkIsLittleEndian();
unsigned int byteChange(unsigned int x, unsigned int y);

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

unsigned int byteChange(unsigned int x, unsigned int y)
{
    unsigned int result;//store result
    unsigned char *result_ptr;
    unsigned char *input_ptr;
    result_ptr = &result;
    //judge endian
    if (checkIsLittleEndian())
    {
        input_ptr = &x;
        *result_ptr = *input_ptr;
        input_ptr = &y;
        for (size_t i = 1; i < sizeof(unsigned int); i++)
        {
            *(result_ptr+i) = *(input_ptr+i);
        }
        
    }
    else
    {
        input_ptr = &y;
        for (size_t i = 0; i < sizeof(unsigned int)-1; i++)
        {
            *(result_ptr+i) = *(input_ptr+i);
        }
        input_ptr = &x;
        *result_ptr = *(input_ptr+sizeof(unsigned int)-2);

    }
    return result;
    
}

int main(){
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;
    unsigned int z = byteChange(x, y);
    printf("%X", z);
    system("pause");
    return 0;
}