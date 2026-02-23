#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{

    char *key = argv[1];

    if (argc != 2)
    {
        printf("Usage ./substitution");
        return 1;
    }
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain characters.\n");
            return 1;
        }
    }

    char *msg = malloc(100 * sizeof(char));
    if (msg == NULL)
    {
        return 1;
    }

    printf("Enter your message: \n");
    fgets(msg, 100, stdin);
    msg[strcspn(msg, "\n")] = '\0';

    char *newkey = malloc(27 * sizeof(char));
    for (int i = 0; i < 26; i++)
    {

        newkey[i] = tolower(key[i]);
    }

    char *new = malloc(100 * sizeof(char));
    int index = 0;
    int rkey = 0;
    for (int i = 0; i < strlen(msg); i++)
    {

        if (islower(msg[i]))
        {

            index = msg[i] - 'a';
            new[i] = newkey[index];
        }
        else if (isupper(msg[i]))
        {
            index = msg[i] - 'A';
            new[i] = toupper(newkey[index]);
        }
    }

    new[strlen(msg) + 1] = '\0';
    printf("%s\n", new);

    free(msg);
    free(new);
    free(newkey);

    return 0;
}
