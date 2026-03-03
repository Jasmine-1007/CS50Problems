#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "functions.h"

#define MAX 9

typedef struct  {
    char* name;
    int votes;

}candidate;

candidate candidates[MAX];
bool compare(char b[], int count){
    for (int i = 0; i < count; i++){
        if(strcmp(b, candidates[i].name) == 0){
            candidates[i].votes +=1;
            return true;
        }
    }
    return false;
}          

int main(int argc, char* argv[]){
    int can_count = argc -1;
    if(can_count> 9){
        printf("Max number of candidate is 9.\n");
        return 1;
    }
    for (int i = 0; i< can_count; i++){
        candidates[i].name = argv[i +1];
        candidates[i].votes = 0;
        printf("%s\n", candidates[i].name);
    }

    int voters =0;

    printf("Number of voters: \n");
    scanf("%d", &voters);
    getchar(); 
    char billet[voters][20];
    for (int i = 0; i < voters; i++){
        printf("Vote: \n");
        fgets(billet[i], 10, stdin);
        billet[i][strcspn(billet[i], "\n")] = '\0';
    }

    
    for(int h = 0; h< voters; h++){

    if(!compare(billet[h], can_count)){
        printf("Invalid Ballot: %s\n", billet[h]);
      
    }
    }

    


    int max_votes = 0;
    for (int i =0; i < can_count; i++){
        if(candidates[i].votes > max_votes){
            max_votes = candidates[i].votes;
        }
    }


    for(int i =0; i < can_count; i++){
        if(candidates[i].votes == max_votes){
            printf("Winner is: %s", candidates[i].name);
        }
    }
   




}