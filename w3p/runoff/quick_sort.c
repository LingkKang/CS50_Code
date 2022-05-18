#include <stdio.h>

int main(void)
{
    int ls[5] = {9, 3, 5, 1, 8};
    int max;
    int ind;
    int mid;
    for (int j = 0; j < 5; j++)
    {
        max = ls[j];
        ind = j;
        for (int i = j + 1; i < 5; i++)
        {
            if (ls[i] > max)
            {
                max = ls[i];
                ind = i;
            }
        }
        if (ind != j)
        {
            mid = ls[j];
            ls[j] = max;
            ls[ind] = mid;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%i\n",ls[i]);
    }
}
