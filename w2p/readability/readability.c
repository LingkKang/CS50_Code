#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);
int round_index(float num);
int decide_level(float raw_index);

int main(void)
{
    string input_text = get_string("Text: ");
    int letters = count_letters(input_text);
    int words = count_words(input_text);
    int sentences = count_sentences(input_text);
    float L = letters * 100.0 / words;
    float S = sentences * 100.0 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    decide_level(index);
}

int count_letters(string input)
{
    int len = strlen(input);
    int letter_num = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            letter_num = letter_num + 1;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            letter_num = letter_num + 1;
        }
    }
    return letter_num;
}

int count_words(string input)
{
    int len = strlen(input);
    int words_num = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] == ' ')
        {
            words_num++;
        }
    }
    return words_num + 1;
}


int count_sentences(string input)
{
    int len = strlen(input);
    int sentences_num = 0;
    for (int i = 0; i <= len; i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            sentences_num++;
        }
    }
    return sentences_num;
}

int decide_level(float raw_index)
{
    string level_text;
    if (raw_index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else if (raw_index >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", round_index(raw_index));
    }
    return 0;
}

int round_index(float num)
{
    int lower_bound = (int) num;
    int higher_bound = (int) num + 1;
    float mid = (float)(lower_bound + higher_bound) / 2;
    if (num > mid)
    {
        return higher_bound;
    }
    else
    {
        return lower_bound;
    }
}
