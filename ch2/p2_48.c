#include<stdio.h>
#include<math.h>

struct array
{
    unsigned short flag;
    char element[100];
};

void reverse(char* header, int len)
{
    unsigned short half_flag = len/2;
    for(int i=0; i<half_flag; i++)
    {
        char temp = header[i];
        header[i] = header[len-i-1];
        header[len-i-1] = temp;
    }
}

void DecimalToBinary(unsigned x)
{
    struct array binary_element;
    // unsigned x = 11118;
    binary_element.flag = 0;
    while (x > 0)
    {
        if(x%2==1)
        {
            binary_element.element[binary_element.flag] = '1';
        }
        else
        {
            binary_element.element[binary_element.flag] = '0';
        }
        binary_element.flag += 1;
        x >>= 1;
    }

    if (binary_element.flag/4*4 != binary_element.flag)
    {
        int temp_flag = binary_element.flag;
        for(int i = (binary_element.flag/4+1)*4; i> temp_flag; i--)
        {
            binary_element.element[binary_element.flag] = '0';
            binary_element.flag++;
        }
    }

    /* for(int i = 0; i < binary_element.flag; i++)
    {
        if(i%4==0)
            printf(" ");
        printf("%c", binary_element.element[i]);
    } */

    reverse(binary_element.element, binary_element.flag);
    printf("\n");
    for(int i = 0; i < binary_element.flag; i++)
    {
        if(i%4==0)
            printf(" ");
        printf("%c", binary_element.element[i]);
    }
}

void FloatToBinary(float x)
{
    struct array binarys;
    binarys.flag = 0;
    if (x>1)
        x = x - (int)x;
    while (binarys.flag < 23)
    {
        x *= 2;
        if (x >= 1)
        {
            binarys.element[binarys.flag++] = '1';
            x -= 1;
        }
        else
        {
            binarys.element[binarys.flag++] = '0';
        }
    }
    for(int i=0; i<binarys.flag; i++)
    {
        if (i % 4 == 0 & i != 0)
        {
            printf(" ");
        }
        printf("%c", binarys.element[i]);
    }
    
}

void BinaryToFloat(char* header, int len)
{
    float decimal_value = 0.0; 
    for(int i=0; i<len; i++)
    {
        if (header[i] == '1')
        {
            decimal_value += 1.0/(1<<(i+1));
        }
        
    }
    printf("%.25f\n", decimal_value);
}

void main(){
    unsigned x = 1;
    char* header = "00011001100110011001101";
    BinaryToFloat(header, 23);
}