#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float n;
    
    int amount;
    
    int coins=0;
    
    // array of coin values 
    int values[] = {25, 10, 5, 1};    
    
    // validates the user input
    do 
    {
        printf("O hai! How much change is owed?\n");
        n = GetFloat ();
    } while (n < 0);
    
    // converting real number to integer with rounding
    amount = round(n * 100);

    // counts the quantity of coins
    for (int i=0; amount > 0; i++)
    {
        if (amount / values[i])
        {
            coins += amount / values[i];
        
            amount %= values[i];
        }
    }
    
    printf("%d\n", coins);
}