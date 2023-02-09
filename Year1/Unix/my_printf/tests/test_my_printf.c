/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** test criterion
*/

#include <stdio.h>
#include "my.h"
#include "printf.h"

int main(void)
{
    int a = 10;
    int *p = &a;
    char test[5];
    test[0] = 't';
    test[1] = 9;
    test[2] = 't';
    test[3] = '\0';

    my_printf ("int = %d, %i, %x, %X, %u, %u, %o, %o\n", 18, 18, 1818, 1818, -20, 18, -18, 18);
    my_printf ("str/char = %s, %c\n","Hello",'1');
    my_printf ("pointer = %p\n", &p);
    my_printf ("percent = %%\n");
    my_printf ("hashtags = %#o, %#x, %#X \n",18, 1818, 1818);
    my_printf ("unprintable = %S\n",test);
    my_printf ("binary = %b\n",18);
    my_printf ("==========================================================\n");
    printf ("int = %d, %i, %x, %X, %u, %u, %o, %o\n", 18, 18, 1818, 1818, -20, 18, -18, 18);
    printf ("str/char = %s, %c\n","Hello",'1');
    printf ("pointer = %p\n", &p);
    printf ("percent = %%\n");
    printf ("hashtags = %#o, %#x, %#X \n",18, 1818, 1818);
    return 0;
}
