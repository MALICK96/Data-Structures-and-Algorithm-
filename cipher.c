/*/
    Date: 04/08/2020
    Program: Implement Cesar Cipher Algorithm
    To encrypt a plaintext into ciphertext
    Author: Malick Diakite  
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void cipher(int key, char *str);

int main(int argc, char *argv[])
{
    int key;
    char str[50];

    if (argc != 2)
    {
        printf("Usage: main key\n");
        exit(1);
    }

    // Convert key into int
    key = atoi(argv[1]);

    if (key != 0)
    {
        printf("Plaintext: ");
        scanf("%[^\n]", str);

        cipher(key, str);
    }

    return 0;
}

void cipher(int key, char *str)
{
    int i, n;

    printf("Plaintext: ");

    // Encryption Logic
    for (i = 0, n = strlen(str); i < n; i++)
    {

        // If i'th character is alphabet
        if (isalpha(str[i]))
        {
            // If i'th char is upper case
            if (isupper(str[i]))
            {
                // Encript It and Print
                printf("%c", (((str[i] - 65 + key) % 26) + 65));
            }
            else
                /* Othewise If lower case
        Encript It and Print*/
                printf("%c", (((str[i] - 97 + key) % 26) + 97));
        }
        else
            // If it not alphabet letter print the it as it is
            printf("%c", str[i]);
    }
    printf("\n");
}