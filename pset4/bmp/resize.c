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
#include <ctype.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    // remember n argument in a "resize" variable
    int resize = atoi(argv[1]);
    
    // validate the resize argument
    if ((isdigit(resize) != 0) || (resize < 1) || (resize > 100))
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // create and resize metadata (BITMAPINFOHEADER) for new image
    BITMAPINFOHEADER bi2 = bi;
    bi2.biHeight = bi2.biHeight * resize;
    bi2.biWidth = bi2.biWidth * resize;  
    
    // determine padding for scanlines (new image)
    int padding = (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine size for new image including new padding
    bi2.biSizeImage = (bi2.biWidth * sizeof(RGBTRIPLE) + padding)  * abs(bi2.biHeight);
   
    // create and resize metadata (BITMAPFILEHEADER) for new image   
    BITMAPFILEHEADER bf2 = bf;
    bf2.bfSize = bi2.biSizeImage + 54; 

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // determine padding for scanlines (old image)
    int paddingOld =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int a = 0; a < resize; a++)
        {
            // set file position indicator in inFile to the beginning of current row
            fseek(inptr, i * (bi.biSizeImage / abs(bi.biHeight)) + bf.bfOffBits, SEEK_SET);
            
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // colored pixel
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // iterate over pixel in outfile "resize"-times
                for (int res = 0; res < resize; res++)
                {
                    // write RGB triple to outfile "resize"-times
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
                // TODO vertical resize
            }
    
            // skip over padding, if any in initial image
            fseek(inptr, paddingOld, SEEK_CUR);
    
            // fill padding with zeroes in new image
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
