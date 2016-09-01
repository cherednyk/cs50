#include <stdio.h>
#include <cs50.h>

int fact(int n);

int main(void)
{
    printf("enter a number: ");
    int a = GetInt() ;
    int b;
    
    b = fact(a);
    
    printf("fact %d = %d\n", a, b);
}

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    } 
    
    return n*fact(n-1);
}