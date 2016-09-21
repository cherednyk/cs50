#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = 9;
    printf("a = %d, b = %d\n", a, b);
    
    a = a ^ b;
    printf("a = a ^ b   a = %2d,  b = %2d\n", a, b);
    b = a ^ b;
    printf("b = a ^ b   a = %2d,  b = %2d\n", a, b);
    a = a ^ b;
    printf("a = a ^ b   a = %2d,  b = %2d\n", a, b);
    
}