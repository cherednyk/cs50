#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("enter a decimal number: \n");
    
    int n;
    
    n = GetInt();
    
    int k;
    
    printf("enter a digit system number: \n");
    
    do
    {
        k = GetInt();
        
    } while ((k < 2) || (k > 9));
    
    int d = 1;
    int power = 0;
    
    do
    {
        d *= k;
        power++;
    } while (d * k <= n);
    
    int bits[power];
    
    printf("the %d base number:\n", k);
    
    int i = 0;
        while (d != 0)
        {
            if (n / d)
            {
                bits[i] = n / d;
                n %= d;
            }
            else
            {
                bits[i] = 0;
            }
            
            d /= k;
            printf("%d", bits[i]);
            
            i++;
        }
    
    printf("\n");
}