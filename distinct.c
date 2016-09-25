#include <stdio.h>

int main(void)
{
    int ar[] = {1,2,3,2,3,4,7,9,8,4,1};
    
    int size = sizeof(ar)/sizeof(ar[0]);
    
    int ar2[size];
    
    for (int i = 0; i < size; i++)
    {
        
    }
    
    for (int i = 0; i <  size; i++)
    {
        printf("%d\n", ar2[i]);
    }
    
    
}