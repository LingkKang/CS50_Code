#include <cs50.h>
#include <stdio.h>

long get_number(void);
int validation(long);
string card_type(long);

int main(void)
{
    long card_num = get_number();
    int val = validation(card_num);
    if (val == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s", card_type(card_num));
    }
}

long get_number(void)
{
    // get the credit card number
    long num = get_long("Number: ");
    return num;
}

int validation(long num)
{
    // test the number is valid or not
    int i;
    int length = 0;
    int first_sum = 0;
    int second_sum = 0; // should include multiplication by 2

    while (num > 0)
    {
        i = num % 10;
        first_sum = first_sum + i;
        num = num / 10;
        length++;
        if (num > 0)
        {
            // in case the total digit number is odd
            i = num % 10;
            i = i * 2;
            if (i >= 10)
            {
                i = i / 10 + i % 10;
            }
            second_sum = second_sum + i;
            num = num / 10;
            length++;
        }
    }

    int sum = first_sum + second_sum;
    if (length != 13 & length != 15 & length != 16)
    {
        return 0;
    }
    else if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


string card_type(long num)
{
    // get the head of the number
    int first_digit;
    int second_digit;
    while (num > 0)
    {
        num = num / 10;
        if (num <= 99 & num > 9)
        {
            second_digit = num % 10;
        }
        if (num <= 9 & num > 0)
        {
            first_digit = num;
        }
    }
    // decide which type the card is
    if (first_digit == 4)
    {
        return "VISA\n";
    }
    else
    {
        int head = first_digit * 10 + second_digit;
        if (head == 34 || head == 37)
        {
            return "AMEX\n";
        }
        else if (head == 51 || head == 52 || head == 53 || head == 54 || head == 55)
        {
            return "MASTERCARD\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
}
