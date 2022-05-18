#include <stdio.h>

int main(void)
{
    int ls[5] = {1, 6, 1, 6, 9};
    int position;
    int mid;
    for (int i = 0; i < 5; i++)
    {
        int max = ls[i];
        position = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (ls[j] > max)
            {
                max = ls[j];
                position = j;
            }
        }
        if (i != position)
        {
            mid = ls[i];
            ls[i] = ls[position];
            ls[position] = mid;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%i\n", ls[i]);
    }
}