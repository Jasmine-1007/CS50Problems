#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"



int main (int argc, char* argv[]){
    if(argc != 4){
        printf("Usage: -filter input output \n");
        return 1;
 
 
    }

    char filter = argv[1][0];

    FILE* iptr = fopen(argv[2], "r");
    if(iptr == NULL){
        printf("Error opening the file\n");
        return 1;
    }
    FILE* optr = fopen(argv[3], "w");

    if(optr == NULL){
        printf("Error opening the file\n");
        return 1;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    fread(&bf, sizeof(bf), 1, iptr);
    fread(&bi, sizeof(bi), 1, iptr);

     if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(optr);
        fclose(iptr);
        printf("Unsupported file format.\n");
        return 6;
    }

    fwrite(&bf, sizeof(bf), 1, optr);
    fwrite(&bi, sizeof(bi), 1, optr);

int width = bi.biWidth;

int height = abs(bi.biHeight);

RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));

if(image == NULL){
    printf("Error allcoating memory \n");
    return 7;
}

  int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;


    // Iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // Read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, iptr);

        // Skip over padding
        fseek(iptr, padding, SEEK_CUR);
    }

switch(filter){

    case 'g':
    grayscale(height,width, image);
    break;

    case 's':
    sepia(height, width, image);
    break;

    case 'r':
    reflect(height, width, image);
    break;

    case 'b':
    blur(height, width, image);
    break;

    default:
    printf("Invalid usage.\n");
    free(image);
        fclose(iptr);
        fclose(optr);
        return 8;


}

   for(int i =0; i < height; i++) {
    fwrite(image[i], sizeof(RGBTRIPLE), width, optr);
    
    for (int k = 0; k < padding; k++)
    {
        fputc(0x00, optr);
    }
   }

   fclose(iptr);
   fclose(optr);
   
   free(image);





}