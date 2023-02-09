/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** mainfile
*/

#include <unistd.h>

void top (unsigned int n);
void down (unsigned int n);
void line (unsigned int n);
int mid (unsigned int n);

void print(int x, char c)
{
    int i = 0;
    while (i < x) {
        write (1, &c, 1);
        i++;
    }
}

void star (unsigned int n)
{
    if ( n > 0 ) {
        top(n);
        line(n);
        mid(n);
        line(n);
        down(n);

    }
}
