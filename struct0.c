#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define SIZE 3

int main(void)
{
    typedef struct
    {
        string name;
        string dorm;
    } sstudent;
    
    sstudent students[SIZE];
    
    for (int i=0; i < SIZE; i++)
    {
        printf("name: \n");
        students[i].name = GetString();
        
        printf("dorm: \n");
        students[i].dorm = GetString();
    }
    
    for (int i=0; i < SIZE; i++)
    {
        printf("%s is in %s\n", students[i].name, students[i].dorm);
    }
    
    for (int i=0; i < SIZE; i++)
    {
        free(students[i].name);
        free(students[i].dorm);
    }
    
}