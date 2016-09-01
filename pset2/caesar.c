#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ABC 26

int main(int argc, string argv[])
{
    // controls inputted arguments / displays error if needed
    if ((argc != 2) || (atoi(argv[1]) < 1))
    {
        printf ("Error. Correct usage: ./caesar <positive int key>\n");
        return 1;
    } 
    
    int key = atoi(argv[1]);
    
    string text = GetString();
    
    // enciphers the plain text according to the key
    for (int j=0, len = strlen(text); j < len; j++)
    {
        // enciphers alphabetic characters only
        if (isalpha(text[j]))
        {
            // initial lower case text printed as lower case enciphered
            if (islower(text[j]))
            {
                printf("%c", (text[j] + key - 'a') % ABC + 'a' );
            }
            // initial upper case text printed as upper case enciphered
            else if (isupper(text[j]))
            {
                printf("%c", (text[j] + key - 'A') % ABC + 'A' );
            }
        }
        // prints non alphabetic characters unchanged
        else
        {
            printf("%c", text[j]);
        }
    }
    
    printf("\n");
    return 0;
}