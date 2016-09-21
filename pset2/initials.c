#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // variables declaration
    string name = GetString();
    
    // prints the first element if it is not ' '
    if (name[0] != ' ') 
    {
        printf("%c", toupper(name[0]));
    }
    
    // prints the first element of every new word in the upper case
    for (int i=0, len = strlen(name); i < len; i++)
    {
        if ((name[i] == ' ') && (name[i + 1] != ' ') && (name[i + 1] != '\0'))
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}