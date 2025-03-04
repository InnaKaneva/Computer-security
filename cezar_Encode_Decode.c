//4. Направете програма, която поддържа както шифриране, така и дешифриране на съобщение,
// съобразно команда, която се въвежда в нея. Програмата да приема многократно команди до срещането на командата "END".
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXN 1000

char* cezar_encode(char* text, int key)
{
    int length=strlen(text);
    char* cipher=(char*) malloc(sizeof(char)*(length+1));
    for(int i=0; i<length; i++)
    {
        if (islower(text[i]))
        {
            cipher[i]=(text[i] - 'a' + key) % 26 + 'a';
        } 
        else if (isupper(text[i]))
        {
            cipher[i]=(text[i] - 'A' + key) % 26 + 'A';
        }
        else if (isdigit(text[i]))
        {
            cipher[i]=(text[i] - '0' + key) % 10 + '0';
        }
        else
        {
            cipher[i]=text[i];
        }
    }

    cipher[length]='\0';
    return cipher;
}

char* cezar_decode(char* text, int key)
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
    char text[MAXN];
    char command[MAXN];
    char* cipher;
    int key;
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    printf("Key: ");
    scanf("%d", &key);
    while (1)
    {
        printf("Command: ");
        scanf("%s", command);
        if(strcmp(command,"encode")==0)
        {
            cipher=cezar_encode(text, key);
            printf("Encode: %s\n",cipher);

        }
        else if (strcmp(command,"decode")==0)
        {
            cipher=cezar_decode(text, key);
            printf("Decode: %s\n",cipher);

        }
        else if (strcmp(command,"END")==0)
        {
            break;
        }
        else
        {
            printf("error\n");
        }
    }

    free(cipher);
    return EXIT_SUCCESS;
}
