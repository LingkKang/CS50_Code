#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = "HI!";
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }

    printf("pointer of s is %p \npointer of t is %p\n", s, t);
    printf("t: %s\n", t);
    free(t);
}