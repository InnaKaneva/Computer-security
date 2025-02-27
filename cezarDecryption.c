#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXN 1000

char* cezar_cipher(char* text, int key)
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
    
    FILE *fileptr=fopen("cipher.txt","r");
    char text[MAXN];
    fgets(text, sizeof(text), fileptr);
    printf("The encrypted message is: %s",text);
    int key;
    printf("Enter a key: ");
    scanf("%d", &key);
    char* cipher=cezar_cipher(text, key);
    printf("The decrypted message is: %s", cipher);

    fclose(fileptr);
    free(cipher);

    return EXIT_SUCCESS;
}