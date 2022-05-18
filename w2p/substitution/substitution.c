#include <cs50.h>
#include <stdio.h>
#include <string.h>

int key_check(string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (key_check(argv[1]) != 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string plain_text = get_string("plaintext:  ");
        int len = strlen(plain_text);
        string cipher_text = plain_text;
        for (int i = 0; i < len; i++)
        {
            if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
            {
                int order = plain_text[i] - 'a' + 1;
                if (argv[1][order - 1] <= 'Z')
                {
                    cipher_text[i] = argv[1][order - 1] - 'A' + 'a';
                }
                else
                {
                    cipher_text[i] = argv[1][order - 1];
                }
            }
            else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
            {
                int order = plain_text[i] - 'A' + 1;
                if (argv[1][order - 1] >= 'a')
                {
                    cipher_text[i] = argv[1][order - 1] + 'A' - 'a';
                }
                else
                {
                    cipher_text[i] = argv[1][order - 1];
                }
            }
        }
        printf("ciphertext: %s\n", cipher_text);
        return 0;
    }
}

int key_check(string key)
{
    int len = strlen(key);
    if (len != 26)
    {
        return 1;
    }
    else
    {
        int letters[26] = {0};
        int order;
        for (int i = 0; i < len; i++)
        {
            if (key[i] <= 'Z')
            {
                order = key[i] - 'A';
                letters[order]++;
            }
            else if (key[i] >= 'a')
            {
                order = key[i] - 'a';
                letters[order]++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (letters[i] != 1)
            {
                return 1;
            }
        }
        return 0;
    }
}