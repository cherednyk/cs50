#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do 
    {
        printf("Please enter a number from 0 to 23:");
        height = GetInt ();
    } while (height < 0 || height > 23);
    
    for (int i = height; i > 0; i--)
    {
        for (int j=0; j < height; j++)
        {
            if (j < i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int j=1; j < height+1; j++)
        {
            if (j > i - 1)
            {
                printf("#");
            }
        }
        
        printf("\n");
    }
}