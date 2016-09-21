#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    printf("enter a decimal number: \n");
    
    n = GetInt();
    
    int d = 1;
    int power = 0;
    
    do
    {
        d *= 2; 
        power++;
    } while (d * 2 <= n);
    
    int bits[power];
    int i = 0;
    
    printf("0b");
    
    if (n > 1)
    {
        while (d != 0) 
        {
            bits[i] = n / d;
            n %= d;
            d /= 2;
            i++;
        }
        
        for (i = 0; i <= power; i++)
        {
            printf("%d", bits[i]);
        }
        printf("\n");
    }
    else if (n == 0)
    {
        printf("0\n");
    }
    else if (n == 1)
    {
        printf("1\n");
    }
}