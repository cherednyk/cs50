#include <stdio.h>
#include <cs50.h>

int steps = 0;

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        steps++;
        return collatz(n / 2);
    }
    else
    {
        steps++;
        return collatz(n * 3 + 1);
    }
}

int main(void)
{
    int n;
    printf("number please: \n");
    n = GetInt();
    
    collatz(n);
    
    printf("steps = %d\n", steps);
}