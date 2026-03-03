#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define HEADER_SIZE 44

int main(int argc, char* argv[]){
    //check for input

if(argc != 4){
    printf("Usage: input output factor \n");
    return 1;
}

float factor = atof(argv[3]);

FILE* iptr = fopen(argv[1], "r");

if(iptr == NULL){
    printf("Could not open file,\n");
    return 1;
}

FILE* optr = fopen(argv[2], "wb");
if(optr == NULL){
    printf("Could not open file.\n");
    return 1;
}

uint8_t header[HEADER_SIZE];


size_t read = fread(header, 1, HEADER_SIZE, iptr);
if(read != 44){
    printf("Did not read all headers.\n");
}

size_t write = fwrite(header, 1, HEADER_SIZE, optr);
if(write != 44){
    printf(
        "Did not write all header.\n"
    );

}
int16_t input;

while(fread(&input, sizeof(input), 1, iptr)){

    
    input = input * factor;
    size_t output = fwrite(&input, sizeof(input), 1, optr);
}

fclose(iptr);
fclose(optr);


    //open both files

    //write headers to output (44 bytes)

                                                                                                           



    //read the rest and multiply by 2


}
