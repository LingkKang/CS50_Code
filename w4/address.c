#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", &n);
    printf("%i\n", *p);

    char *str = "Hi!";
    printf("%p\n", str);

    printf("%c\n", str[0]);
    printf("%c\n", *str);
    // Pointer Arithmetic

    printf("%c\n", str[1]);
    printf("%c\n", *(str + 1));

    printf("%c\n", str[2]);
    printf("%c\n", str[3]);

    int numbs[] = {4, 6, 8, 2, 7, 5, 0};
    printf("%i\n", *numbs);
    printf("%i\n", *(numbs + 80));
}