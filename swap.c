#include <stdio.h>

int main(void)
{
    int a = 2;
    int b = 6;
    printf("a = %d, b = %d\n", a, b);
    
    a = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    b = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    a = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    
    
}