#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    // validates the user input
    do 
    {
        printf("Please enter a number from 0 to 23:");
        height = GetInt ();
    } while (height < 0 || height > 23);
    
    // outer loop
    for (int i = height; i > 0; i--)
    {
        // inner loop
        for (int j=0; j < height; j++)
        {
            if (j < i - 1)
            {
                // prints spaces
                printf(" "); 
            }
            else
            {
                // prints hashes
                printf("#"); 
            }
        }
        printf("#\n");
    }
}