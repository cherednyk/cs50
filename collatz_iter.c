#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    
    printf("enter a number: \n");
    
    n = GetInt();
    int ni = n;
    int steps = 0;
    
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n *= 3;
            n++;
        }
        steps++;
        printf("n = %d\n", n);
    }
    
    printf("it took %d steps, to collatz %d to 1\n", steps, ni);
}