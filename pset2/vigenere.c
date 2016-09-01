#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

#define ABC 26

int keyValid(int argc, string key);

int main(int argc, string argv[])
{
    
    string key = argv[1];
    
    // if key is invalid program interrupts
    if (keyValid(argc, key)) 
    { 
        return 1;
    }
    
    string text = GetString();
    
    int keyLen = strlen(key);
    int textLen = strlen(text);
    int notAlpha = 0;
    
    // converts keyword to lower case
    for (int j=0; j < keyLen; j++)
    {
        key[j] = tolower(key[j]);
    }
    
    int newKey;
    
    // enciphers the plain text according to the keyword  
    for (int i=0; i < textLen; i++)
    {
        // counts non alphabetic characters
        if (!(isalpha(text[i])))
        {
            notAlpha++;
            printf("%c", text[i]);
        } 
        // enciphers upper case letters
        else if (isupper(text[i]))
        {
            newKey = (key[(i - notAlpha) % keyLen] - 'a') % ABC;
            
            printf("%c", (text[i] + newKey - 'A') % ABC + 'A');
        }
        // enciphers lower case letters
        else if (islower(text[i]))
        {
            newKey = (key[(i - notAlpha) % keyLen] - 'a') % ABC;
            
            printf("%c", (text[i] + newKey - 'a') % ABC + 'a');
        }
    }
    printf("\n");
    
    return 0;
}

// validates the keyword argument
int keyValid(int argc, string key)
{
    // 2 argc is a must
    if (argc != 2)
    {
        printf ("Error. Correct usage: ./vigenere <keyword>\n");
        return 1;
    }
    else
    {   
        // only alphabetic characters are allowed as keyword
        for (int i=0, len = strlen(key); i < len; i++)
        {
            if (isalpha(key[i]) == 0) 
            {
                printf ("Keyword must only contain letters A-Z and a-z\n"); 
                return 1;
            }
        }
    }
    
    return 0;
}