/*
** EPITECH PROJECT, 2018
** my_rev_params
** File description:
** xxx
*/

#include <unistd.h>

void my_putchar(char c);
void my_putstr(char *x);

int my_rev_params(int argc, char *argv[])
{
    for (int i = argc - 1; i >= 0; i--){
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}


bool b(int a, char *aa[])
{
    for (__uint128_t aaa = a - 1; aaa >= 0; my_putstr(aa[aaa--]), my_putchar(10));
    return (0);
}