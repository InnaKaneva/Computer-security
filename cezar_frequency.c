#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_LETTER 10

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

int* count_frequencies(char* cipher)
{
    int length=strlen(cipher);
    int* counts=(int*) malloc(sizeof(int) * ALPHA_LENGTH);
    memset(counts,0,sizeof(int) * ALPHA_LENGTH);
    for (int i = 0; i < length; i++)
    {
        char symbol=tolower(cipher[i]);
        if(symbol>= 'a' && symbol<= 'z')
        {
            int position=symbol - 'a';
            counts[position]++;
        }
    }
    return counts;
}

int get_max_index(int* counts)
{
    int max_index=0;
    for (int i = 0; i < ALPHA_LENGTH; i++)
    {
        if(counts[i]>counts[max_index])
        {
            max_index=1;
        }
    }
    return max_index;
}

int main()
{
    char cipher[MAXN];
    scanf("%s", cipher);

    char common_letters[COMMON_LETTER]={'e','t','a','o','i','n','s','r','h','l'};
    int* frequencies=count_frequencies(cipher);
    char most_common_letter=get_max_index(frequencies)+'a';
    for (int i = 0; i < COMMON_LETTER; i++)
    {
        int key=abs(most_common_letter - common_letters[i]);
        char* plaintext=cezar_decipher(cipher,key);
        printf("Key = %d -> %s\n",key, plaintext);
        free(plaintext);
    }
    return EXIT_SUCCESS;
}