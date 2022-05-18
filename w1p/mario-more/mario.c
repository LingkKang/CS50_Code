#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // print spaces before bricks
        for (int k = n - i - 1; k > 0; k--)
        {
            printf(" ");
        }

        // print leftside bricks
        for (int j = i + 1; j > 0; j--)
        {
            printf("#");
        }

        printf("  ");

        // print rightside bricks
        for (int m = i + 1; m > 0; m--)
        {
            printf("#");
        }
        printf("\n");
    }
}