#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
    char word_1[2][100];
    printf("Enter your word: \n");
    scanf("%99s", word_1[0]);

    printf("Enter your word: \n");
    scanf("%99s", word_1[1]);
    for(int j=0; j<2; j++){
for (int i=0; i < strlen(word_1[j]); i++){
    if(isalpha(word_1[j][i]))
        word_1[j][i] = toupper(word_1[j][i]);
    }
    }
    
   
    int score[2] = {0,0};
    for (int h=0; h<2; h++){
    for (int i=0; i< strlen(word_1[h]); i++){
        if(word_1[h][i] == 'A' || word_1[h][i] == 'E' || 
    word_1[h][i] == 'I' || word_1[h][i] == 'L' || 
    word_1[h][i] == 'N' || word_1[h][i] == 'O' || 
    word_1[h][i] == 'R' || word_1[h][i] == 'S'){
            score[h] +=1;
        }
        else if(word_1[h][i] == 'G' || word_1[h][i] == 'D'){
            score[h] +=1;
        }
        else if (word_1[h][i] == 'B' || word_1[h][i] == 'C' || 
         word_1[h][i] == 'M' || word_1[h][i] == 'P')
{
    score[h] += 3;
}
else if (word_1[h][i] == 'F' || word_1[h][i] == 'H' || 
         word_1[h][i] == 'V' || word_1[h][i] == 'W' || 
         word_1[h][i] == 'Y')
{
    score[h] += 4;
}
else if (word_1[h][i] == 'K')
{
    score[h] += 5;
}
else if (word_1[h][i] == 'J' || word_1[h][i] == 'X')
{
    score[h] += 8;
}
else if (word_1[h][i] == 'Q' || word_1[h][i] == 'Z')
{
    score[h] += 10;
}


    }
}
    printf("score is: %d\n", score[0]);
    printf("score is: %d\n", score[1]);
    return 0;
}