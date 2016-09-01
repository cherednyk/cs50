#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int sigma(int);
bool argInvalid(int argc, char*);
void countNprint(int);

int main(int argc, char* argv[])
{
    if (argInvalid(argc, argv[1]))
    {
        return 0;
    }
    
    int n = atoi(argv[1]);
    
    countNprint(n);
}

void countNprint(int n)
{
    int res;
    
    res = sigma(n);
    
    printf("sigma of %d = %d\n", n, res);
}


bool argInvalid(int argc, char* argv)
{
    if (argc != 2) 
    {
        printf("Usage: ./sigma <int>\n");
        return true;
    }
    
    int len = strlen(argv);
    
    for (int i=0; i < len; i++)
    {
        if (isalpha(argv[i]))
        {
            printf("Usage: ./sigma <int>\n");
            return true;
        }
    }
    return false;
}

int sigma(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return (n + (sigma(n - 1)));
    }
}