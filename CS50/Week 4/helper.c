#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE average;
    for(int i = 0; i< height; i++){
        for(int j =0; j < width; j++){

        average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /3.0);
        image[i][j].rgbtBlue = average;
        image[i][j].rgbtGreen = average;
        image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE sepiaRed; BYTE sepiaGreen; BYTE sepiaBlue;
    for(int i =0; i < height; i++){
        for(int j =0; j < width; j++){

sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
if(sepiaRed > 255 ) sepiaRed = 255;
sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
if(sepiaGreen > 255 ) sepiaGreen = 255;
sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
if(sepiaBlue > 255 ) sepiaBlue = 255;

image[i][j].rgbtRed = sepiaRed;
image[i][j].rgbtGreen = sepiaGreen;
image[i][j].rgbtBlue = sepiaBlue;
        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i =0; i < height; i++){
        for(int j =0; j < width /2; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j -1];
            image[i][width - j -1] = temp;


        }}

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE (*imagecp)[width] = calloc(height, width* sizeof(RGBTRIPLE ));
    for(int i =0; i < height; i++){
        for(int j =0; j < width; j++){

            imagecp[i][j] = image[i][j];

    

                    }} 

    for(int i =0; i < height; i++){
        for(int j =0; j < width; j++){

            int red = 0; int green = 0; int blue = 0;
            int count = 0;
            for (int x =  -1; x<= 1; x++ ){
                for(int y = -1; y<= 1; y++){
                    int ni = i + x;
                    int nj = j + y;

                    if(ni >=0 && ni <height ){
                        if(nj >=0 && nj <width){
                            red += imagecp[ni][nj].rgbtRed;
                            green+= imagecp[ni][nj].rgbtGreen;
                            blue += imagecp[ni][nj].rgbtBlue;
                            count ++;

                        }
                    }

                }
            }


            image[i][j].rgbtRed = round((float) red/count);
            image[i][j].rgbtGreen = round((float) green/count);
            image[i][j].rgbtBlue = round((float) blue/count);

        
                    }} 


    return;
}



void egde(int height, int width, RGBTRIPLE image[height][width]){
    RGBTRIPLE (*imagecp)[width] = calloc(height, (width)* sizeof(RGBTRIPLE));
    for (int i =0 ; i < width; i++){
        for (int j =0; j < height; j++){
            imagecp[i][j] = image[i][j];


        }
    }

    int ni = 0; int nj = 0;
    int arrayX[9] = {-1, -2, -1, 0,0,0,1,2,1 };
                    int arrayY[9] = {-1, 0, 1, -2,0,2,-1,0,1 };

    for (int i=0; i < width; i ++){
        for (int j =0; j < height; j++){
            

            int h = 0;
            int GXRed = 0; int GXGreen = 0; int GXBlue = 0;
            int GYRed = 0; int GYGreen = 0; int GYBlue = 0;
            for (int x = -1; x<=1; x++){
                for(int y = -1; y<=1; y++){
                    
                    

                    ni = i + x;
                    nj = j+ y;
                    //handle edge
                    if(ni <0 || ni >= height || nj <0 || nj >= width){
                        h++;
                        continue;
                    }

                    GXRed += imagecp[ni][nj].rgbtRed * arrayX[h];
                    GXGreen += imagecp[ni][nj].rgbtGreen * arrayX[h];
                    GXBlue += imagecp[ni][nj].rgbtBlue * arrayX[h];

                    GYRed += imagecp[ni][nj].rgbtRed * arrayY[h];
                    GYGreen += imagecp[ni][nj].rgbtGreen * arrayY[h];
                    GYBlue += imagecp[ni][nj].rgbtBlue * arrayY[h];

                    h++;
                }
            }

            int red = round(sqrt(GXRed*GXRed + GYRed*GYRed));
        int green = round(sqrt(GXGreen*GXGreen + GYGreen*GYGreen));
        int blue = round(sqrt(GXBlue*GXBlue + GYBlue*GYBlue));

        if (red > 255) red = 255;
        if (green > 255) green = 255;
        if (blue > 255) blue = 255;

        image[i][j].rgbtRed = red;
        image[i][j].rgbtGreen = green;
        image[i][j].rgbtBlue = blue;
    }
    

    free(imagecp);
    return;
}