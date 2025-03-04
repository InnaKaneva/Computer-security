//1. Прочетете съдържанието на файла cipher.txt.
//2. Дешифрирайте съобщението, като приемете, че ключът е 3.
//3. Направете функция, която записва декодираното съобщение във файл с име plaintext.txt

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

void write_file(char* cipher)
{
FILE *fileptr=fopen("plaintext.txt","w");
fprintf(fileptr, cipher);

fclose(fileptr);
}

int main()
{
    
    FILE *fileptr1=fopen("cipher.txt","r");
    char text[MAXN];
    fgets(text, sizeof(text), fileptr1);
    printf("Encrypted message: %s\n",text);
    int key;
    printf("Key: ");
    scanf("%d", &key);
    char* cipher=cezar_cipher(text, key);
    printf("Decrypted message: %s", cipher);
    write_file(cipher);

    fclose(fileptr1);
    free(cipher);
    return EXIT_SUCCESS;
}
