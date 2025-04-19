#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_valid_key(string s);
char rotate(char c, int key);

int main(int argc, string argv[]) // Argument count, vector
{
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); // Convert key string to integer

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

bool is_valid_key(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

 // Circular shift
char rotate(char c, int key)
{
    if (isupper(c))
    {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else
    {
        return c;
    }
}