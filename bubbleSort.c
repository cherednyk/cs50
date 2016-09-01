#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void show(int a[], int l, string text);
void sort(int values[], int len);

int main(int argc, string argv[])
{
    int numz[] = {6,5,7,8,2,9,3,1,4};
    int len = sizeof(numz) / sizeof(int);
    
    sort(numz, len);
    show(numz, len, "sorted: ");
}


void sort(int values[], int len)
{
    int temp;
    
    int decreaseLoop = 0;
    
    int swap = -1;
    
    if (len > 1)
    {
        while (swap != 0)
        {
            swap = 0;
            for (int i=0; i < len - 1 - decreaseLoop; i++)
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
}


void show(int a[], int l, string text)
{
    printf("%s", text);
    for (int j=0; j < l; j++)
    {
        printf("%d", a[j]);
    }
    
    printf("\n");
}