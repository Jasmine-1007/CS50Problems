#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int word = 0;
int letter = 0;
int sentence = 0;

int count_letter(char* p){
    for (int i=0; i< strlen(p); i++){
        if(isalpha(p[i])){
            letter+=1;
        }
    }
    return letter;
}

int count_word(char* p){
    for (int i=0; i< strlen(p); i++){
        if(p[i] == ' '){
            word+=1;
        }
    }
    return word;
}

int count_sentence(char* p){
    for (int i=0; i <strlen(p); i++){
        if(p[i] == '.' || p[i] == '?' || p[i] == '!'){
            sentence +=1;
        }
    }
    return sentence;

}

int main (void){
    char *p = malloc(1000 * sizeof(char));
    if(p == NULL) {return 1;}
    printf("Input your text:  ");
    fgets(p, 1000, stdin);

    int letter = count_letter(p);
    printf("%d\n", letter);
    int word = count_word(p);
    printf("%d\n", word);
    int sentence = count_sentence(p);
    printf("%d\n", sentence);


int L = letter * 100/word;
int S = sentence * 100/word;

int index = 0.0588 * L - 0.296 * S - 15.8;
printf("%d\n", index);

free(p);

}


