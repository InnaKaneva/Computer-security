#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXN 1024

char* vigenere_decode(char* cipher,char* key)
{
    int text_length=strlen(cipher);
    int key_length=strlen(key);
    char* plaintext=(char*) malloc(sizeof(char)*(text_length+1));
    memset(plaintext,'\0',sizeof(char)*(text_length+1));
    for(int i=0; i<text_length; i++){
        if(isalpha(cipher[i]))
        {
            int shift=tolower(key[i%key_length])-'a';
            if(islower(cipher[i]))
            {
                plaintext[i]=(cipher[i]-shift-'a'+26)%26 +'a';
            }
            else
            {
                plaintext[i]=(cipher[i]-shift-'A'+26)%26+'A';
            }
        }
        else
        {
            plaintext[i]=cipher[i];
        }
    }
    plaintext[text_length]='\0';
    return plaintext;
}

int read_file(char* filename, char* plaintext)
{
    FILE* fileptr=fopen(filename,"r");
    if(fileptr==NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }
    if(fgets(plaintext,MAXN,fileptr)==NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }
    fclose(fileptr);
    return EXIT_SUCCESS;
}
void write_file(char* filename, char* cipher)
{
    FILE* fileptr=fopen(filename,"a");
    fprintf(fileptr,"%s",cipher);
    fclose(fileptr);
}
int main()
{
    char cipher[MAXN];
    read_file("vigenereCipher.txt",cipher);
    printf("Cipher: %s\n",cipher);

    char key[MAXN];
    read_file("vigenereKey.txt",key);
    printf("The key is: %s\n",key);

    char* plaintext=vigenere_decode(cipher,key);
    printf("%s",plaintext);
    write_file("vigenerePlaintext.txt",plaintext);

    free(plaintext);
    return EXIT_SUCCESS;
}