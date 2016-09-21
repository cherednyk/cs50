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
    if (argc != 3)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];
    char* outfile = argv[2];

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

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
             
            if (triple.rgbtRed == 255)
            {
                triple.rgbtBlue = 255;
                triple.rgbtGreen = 255;
                
            }
            
            if (triple.rgbtRed <= 245 && triple.rgbtRed > 223) {
                triple.rgbtRed = 211;
                triple.rgbtBlue = 211;
                triple.rgbtGreen = 211;
            } else if (triple.rgbtRed <= 223 && triple.rgbtRed > 201) {
                triple.rgbtRed = 189;
                triple.rgbtBlue = 189;
                triple.rgbtGreen = 189;
            } else if (triple.rgbtRed <= 201 && triple.rgbtRed > 179) {
                triple.rgbtRed = 168;
                triple.rgbtBlue = 168;
                triple.rgbtGreen = 168;
            } else if (triple.rgbtRed <= 179 && triple.rgbtRed > 157) {
                triple.rgbtRed = 147;
                triple.rgbtBlue = 147;
                triple.rgbtGreen = 147;
            } else if (triple.rgbtRed <= 157 && triple.rgbtRed > 135) {
                triple.rgbtRed = 126;
                triple.rgbtBlue = 126;
                triple.rgbtGreen = 126;
            } else if (triple.rgbtRed <= 135 && triple.rgbtRed > 113) {
                triple.rgbtRed = 105;
                triple.rgbtBlue = 105;
                triple.rgbtGreen = 105;
            } else if (triple.rgbtRed <= 113 && triple.rgbtRed > 91) {
                triple.rgbtRed = 84;
                triple.rgbtBlue = 84;
                triple.rgbtGreen = 84;
            } else if (triple.rgbtRed <= 91 && triple.rgbtRed > 69) {
                triple.rgbtRed = 63;
                triple.rgbtBlue = 63;
                triple.rgbtGreen = 63;
            } else if (triple.rgbtRed <= 69 && triple.rgbtRed > 47) {
                triple.rgbtRed = 42;
                triple.rgbtBlue = 42;
                triple.rgbtGreen = 42;
            } else if (triple.rgbtRed <= 47 && triple.rgbtRed > 25) {
                triple.rgbtRed = 21;
                triple.rgbtBlue = 21;
                triple.rgbtGreen = 21;
            } else if (triple.rgbtRed <= 25) {
                triple.rgbtRed = 0;
                triple.rgbtBlue = 0;
                triple.rgbtGreen = 0;
            }

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
