/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;
//#include "jpg.h"

int main(int argc, char* argv[])
{
    // TODO
    if (argc != 1)
    {
        printf("usage: no arguments needed\n");
        return 1;
    }
    
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("could not open card.raw\n");
        return 2;
    }
    
    typedef struct
    {
        BYTE first;
        BYTE second;
        BYTE third;
        BYTE fourth;
        BYTE ar[508];
    } __attribute__((__packed__))
    JPGFOUR;

    JPGFOUR jpg;
    int image = 1; // bool
    int newImage = 0; // increments after writing closure
    char title[50]; // array for img names
    
    long tmpPos;
    
    while(feof(inptr) == 0)
    {
        fread(&jpg, sizeof(JPGFOUR), 1, inptr);
        
        if ((jpg.first == 0xff && jpg.second == 0xd8 && jpg.third == 0xff) && (jpg.fourth == 0xe0 || jpg.fourth == 0xe1))
        {
            image = 1;
            sprintf(title, "%03d.jpg", newImage);
            
            FILE* img = fopen(title, "a");
            if (img == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "could not create\n");
                return 3;
            }
            
            while (image)
            {
                fwrite(&jpg, sizeof(JPGFOUR), 1, img);
                
                tmpPos = ftell(inptr);
                int end = fread(&jpg, sizeof(JPGFOUR), 1, inptr);
                
                if ((jpg.first == 0xff && jpg.second == 0xd8 && jpg.third == 0xff) && (jpg.fourth == 0xe0 || jpg.fourth == 0xe1))
                {
                    image = 0;
                    
                    newImage++;
                    fclose(img);
                    fseek(inptr, tmpPos, SEEK_SET);
                } 
                else if (end != 1)
                {
                    fclose(img);
                    break;
                } 
            } ;
        }
    }
    
    fclose(inptr);
    
    return 0;
}
