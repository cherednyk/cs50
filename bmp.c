/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./copy infile \n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine padding for scanlines
   int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
   
   int tab[256];
   
   tab[0] = 0;
   
   
   int min = 255;
   int max = 0;
   
   // http://www.rapidtables.com/convert/color/rgb-to-hex.htm
    
    // iterate over scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple 
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            printf("color = %d\n", triple.rgbtRed);
            
            for (int t = start; t < 255; t++)
            {
                if (triple.rgbtRed == tab[t])
                {
                    break;
                }
                
                
                
            }
            
            /*
            if (triple.rgbtRed < min)
            {
                min = triple.rgbtRed;
            }
            
            if (triple.rgbtRed > max)
            {
                max = triple.rgbtRed;
            }
            */
            
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);
    
    printf("min = %d\n", min);
    printf("max = %d\n", max);
    
    for (int t = 0; t < 255; t++)
    {
        printf("pixel = %d\n", tab[t]);
    }

    // that's all folks
    return 0;
}
