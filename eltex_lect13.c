#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a = 'A';
    char b = 'B';
    char *ptr1;
    char **ptr2;
    ptr1 = &a;
    ptr2 = &ptr1;
    printf("%c\n", *ptr1);
    printf("%c\n", **ptr2);
    *ptr2 = &b; // Т.к. *ptr2 вернёт ptr1, мы можем указать ему ссылку на другую переменную.
    printf("%c\n", *ptr1);
    printf("%c", **ptr2);
    return 0;
}
