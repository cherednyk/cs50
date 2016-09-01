#include <stdio.h>

void swap(int* a, int* b);

int main(void)
{
    int x = 1;
    int y = 5;
    
    int * z = &x;
    
    printf("z = %i\n", *z);
    
    printf("initial values:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
    swap(&x, &y);
    
    printf("swapped vlues:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
    printf("z = %i\n", *z);
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}