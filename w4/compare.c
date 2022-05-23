#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    char *t = "HY!";

    if (*(s + 1) == *(t + 1))
    {
        printf("%c, same\n", s[1]);
    }
    else
    {
        printf("%c, different, %c\n", s[1], t[1]);
    }
}