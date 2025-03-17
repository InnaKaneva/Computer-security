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

int read_cipher(char* filename, char* cipher)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void write_text(char* filename, char* text, int key)
{
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "Key= %d -> %s\n",key, text);
    fclose(fp);
}

int main()
{
    char cipher[MAXN];
    read_cipher("cipher.txt", cipher);

    for (int key = 0; key < ALPHA_LENGTH; key++)
    {
        char* text=cezar_decipher(cipher, key);
        printf("Key= %d -> %s\n", key, text);

        write_text("plaintext.txt",text,key);
        free(text);
    }
    
    return EXIT_SUCCESS;
}