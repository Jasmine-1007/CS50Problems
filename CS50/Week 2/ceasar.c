#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char rotate(int key, char ch){
    if(isupper(ch)){
        return 'A' + (ch - 'A' + key)%26;
    }
    else if(islower(ch)){
        return 'a' + (ch - 'a' + key)%26;
    }
    else {
        return ch;
    }
}

int main (int argc, char *argv[]){

  
    if(argc != 2){
        printf("Usage: ./Caesar \n");
        return 1;
    }
    char* conv;
    int key = strtol(argv[1], &conv, 10);
    if(*conv != '\0'){
        
        printf("Usage: ./Caesar \n");
        return 1;
    }

    printf("%d\n", key);

    char* msg = malloc(1000 * sizeof(char));
    if(msg == NULL) {return 1;}
    
    printf("Enter your message: \n");

    fgets(msg, 1000, stdin);
    msg[strcspn(msg, "\n")] = '\0';

    int len = strlen(msg);
    char new[len+ 1];
    for (int i =0; i < len; i++){
       new[i] = rotate( key, msg[i]);

    }
    new[len] = "\0";
    printf("%s\n", new);


    return 0;

}