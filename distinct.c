#include <stdio.h>

int main(void)
{
    int ar[] = {1,2,3,2,3,4,7,};
    
    int size = sizeof(ar)/sizeof(ar[0]);
    int size2=0, pos = 0;
    
    int array2[size];
    array2[0] = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (ar[i] == array2[j])
            {
                printf("same elements: %d and %d\n", ar[i], array2[j]);
            }
            else
            {
                array2[pos] = ar[i];
                pos++;
                size2++;
                break;
            }
                
        }
        
    }
    
    for (int i = 0; i <  size2; i++)
    {
        printf("%d\n", array2[i]);
    }
    
    
}