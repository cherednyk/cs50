#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    printf("enter a decimal number: \n");
    
    n = GetInt();
    
    int d = 1;
    int power = 0;
    int hex = 16;
    
    do
    {
        d *= hex; 
        power++;
    } while (d * hex <= n);
    
    printf("0x");
    
    while (d != 0)
    {
        if (n / d < 10)
        {
            printf("%d", n / d);
        }
        else
        {
            switch (n / d)
            {
                case 10: 
                    printf("A");
                    break;
                case 11: 
                    printf("B");
                    break;
                case 12: 
                    printf("C");
                    break;
                case 13: 
                    printf("D");
                    break;
                case 14: 
                    printf("E");
                    break;
                case 15: 
                    printf("F");
                    break;
            }
        }
        
        n %= d;
        d /= hex;
    }
    
    printf("\n");
}