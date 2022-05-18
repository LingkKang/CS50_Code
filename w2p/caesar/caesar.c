#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_digits(int, string);
string cipher(int, string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (check_digits(strlen(argv[1]), argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // convert the string into an integer
        int key = atoi(argv[1]);
        string plain_text = get_string("plaintext:  ");
        string cipher_text = cipher(key, plain_text);
        printf("ciphertext: %s\n", cipher_text);
        return 0;
    }
}

int check_digits(int len, string str)
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 1;
        }
    }
    return 0;
}


string cipher(int key, string plaintext)
{
    int text_len = strlen(plaintext);
    for (int i = 0; i < text_len; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            int new_num = plaintext[i] + key;
            if (new_num > 'z')
            {
                plaintext[i] = (new_num - 'a' + 1) % 26 + 'a' - 1;
            }
            else
            {
                plaintext[i] = plaintext[i] + key;
            }
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            int new_num = plaintext[i] + key;
            if (new_num > 'Z')
            {
                plaintext[i] = (new_num - 'A' + 1) % 26 + 'A' - 1;
            }
            else
            {
                plaintext[i] = plaintext[i] + key;
            }
        }
    }
    return plaintext;
}