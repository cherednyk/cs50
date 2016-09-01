#include <stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    int* x;
    int y;
    
    x = malloc(sizeof(int));
    
    *x = 44;
    
    y = *x;
    
    printf("x = %p\n", x);
    
    printf("y = %d\n", y);
    
}