//1. Прочетете съдържанието на файла cipher.txt.
//2. Дешифрирайте съобщението, като приемете, че ключът е 3.
//3. Направете функция, която записва декодираното съобщение във файл с име plaintext.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

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

void write_text(char* filename, char* text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

int main()
{
    char cipher[MAXN];
    read_cipher("cipher.txt", cipher);
    int key;
    printf("Enter a key: ");
    scanf("%d", &key);
    char* plaintext = cezar_decipher(cipher, key);
    printf("Plain text: %s", plaintext);
    write_text("plaintext.txt", plaintext);
    free(plaintext);
    return EXIT_SUCCESS;
}