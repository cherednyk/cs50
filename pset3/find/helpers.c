/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool binSearch(int value, int values[], int min, int max)
{
    int mid;
    if (max<min)
    {
        return false;
    }
    else 
    {
        mid = (min + max) / 2;
    }
    
    if (values[mid] < value)
    {
        return binSearch(value, values, mid+1, max);
    }
    else if (values[mid] > value)
    {
        return binSearch(value, values, min, mid-1);
    }
    else  
    {
        return true;
    }
    
    return false;
}
 
 
bool search(int value, int values[], int n)
{
    if (n < 0) 
    {
        return false;
    }
    
    for (int i=0; i < n; i++)
    {
        if (value == values[i])
        {
            return true;
        }
        
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp;
    
    int decreaseLoop = 0;
    
    int swap = -1;
    
    if (n > 1)
    {
        while (swap != 0)
        {
            swap = 0;
            for (int i=0; i < n - 1 - decreaseLoop; i++)
            {
                if (values[i] > values[i + 1])
                {
                    temp = values[i];
                    values[i] = values[i + 1];
                    values[i + 1] = temp;
                    swap++;
                }
            }
            
            decreaseLoop++;
        }
    }
    return;
}
