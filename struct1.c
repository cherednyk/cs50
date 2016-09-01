#include <stdio.h>
#include <cs50.h>

#define ST_QTY 3

int main(void)
{

    typedef struct
    {
        string name;
        string dorm;
            
    } student;

    student students[ST_QTY];
    
    for (int i=0; i < ST_QTY; i++)
    {
        printf("student's name: ");
        students[i].name = GetString();
        
        printf("student's dorm: ");
        students[i].dorm = GetString();
    }
    
    FILE* file = fopen("students.csv", "w");
    if (file != NULL)
    {
        for (int i=0; i < ST_QTY; i++)
        {
            fprintf(file, "%s, %s\n", students[i].name, students[i].dorm);
        }
        fclose(file);
    }
    
    for (int i=0; i < ST_QTY; i++)
    {
        free(students[i].name);
        free(students[i].dorm);
    }
    
}

