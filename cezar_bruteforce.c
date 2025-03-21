#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000
#define ALPHA_LENGTH 26

char* cezar_decipher(char* text, int key)
{
    int length=strlen(text);
    char* cipher=(char*) malloc(sizeof(char)*(length+1));
    for(int i=0; i<length; i++)
    {
        if (islower(text[i]))
        {
            cipher[i]=(text[i] - 'a' - key + 26) % 26 + 'a';
        } 
        else if (isupper(text[i]))
        {
            cipher[i]=(text[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if (isdigit(text[i]))
        {
            cipher[i]=(text[i] - '0' - key + 10) % 10 + '0';
        }
        else
        {
            cipher[i]=text[i];
        }
    }

    cipher[length]='\0';
    return cipher;
}

int main()
{
    char cipher[MAXN];
    scanf("%s", cipher);

    for (int key = 0; key < ALPHA_LENGTH; key++)
    {
        char* text=cezar_decipher(cipher, key);
        printf("Key= %d -> %s\n", key, text);

        free(text);
    }
    
    return EXIT_SUCCESS;
}