#include <stdio.h>
#include <cs50.h>

bool binSearch(int value, int values[], int min, int max);
int findMid(int min, int max);

int main(void)
{
    int numz[] = {0,1,2,3,4,5,6,7,8,9};
    int len = sizeof(numz) / sizeof(int);
    
    int target = 1;
    
    int min, max;
    
    min = 0;
    max = len-1;
    
    printf(binSearch(target, numz, min, max) ? "true\n" : "false\n");
}


bool binSearch(int value, int values[], int min, int max)
{
    int mid;
    if (max<min)
    {
        return false;
    }
    else 
    {
        mid = findMid(min, max);
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


int findMid(int min, int max)
{
    int mid;
    mid = (min + max) / 2;
    return mid;
}

    