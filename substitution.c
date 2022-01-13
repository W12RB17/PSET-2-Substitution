// this program encrypts a message given by the user using a 26 character key, replacing every letter of the alphabet with character of the key
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("\nYou did not enter a valid argument...\n\n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("\nKey must contain 26 characters.\n\n");
        return 1;
    }

    int contador = 0;
    while (contador < 26)
    {
        for (int i = contador + 1; i < 26; i++)
        {
            if (argv[1][contador] == argv[1][i])
            {
                printf("\nperro no repita letras\n\n");
                return 1;
            }
        }
        contador ++;    
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    { 
        if (isalpha(argv[1][i]) == 0)
        {
            printf("\nKey must only contain letters\n\n");
            return 1;
        }
    }

    string plaintext = get_string("\nPlaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            if (isalpha(plaintext[i]))
            {
                int perro = plaintext[i] % 97;
                printf("%c", tolower(argv[1][perro]));
            }
        }

        
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int perro = plaintext[i] % 65;
                printf("%c", toupper(argv[1][perro]));
            }
        }

        else
        {
            printf("%c", plaintext[i]);
        }  
    }
    printf("\n\n");
}
            