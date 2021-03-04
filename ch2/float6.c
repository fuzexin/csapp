#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main(){
    int value = 0;
    int flag = 0;
    int exp = 0;
    float sig = 0;
    float result = 0;
    float pow_value = 0;
    float sig_1 = 0;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 1; j < 7; j++)
        {
            for (size_t k = 0; k < 4; k++)
            {
                flag = (i == 0) ? 1 : -1;
                exp = j - 3;
                sig = 0;
                for(size_t l = 2; l > 0; l--)
                {
                    if(k%2 == 1)
                    {
                        sig += 1.0/(1<<l);
                    }
                    k >>= 1;
                }
                pow_value = pow(2, exp);
                sig_1 = 1+sig;
                result = flag * pow_value * sig_1;
                printf("%f\n", result);
            }
            
        }
        
    }
    
}