/*
** EPITECH PROJECT, 2021
** infin_add.c
** File description:
** xxx
*/

#include <stdlib.h>

void write(int i, char *c, int j);
void my_putstr(char *c);
int my_strlen(char *c);
void my_putchar(char c);
int my_str_isnum(char *c);

int my_puterror(char const *str )
{
    int i = 0;
    char c;
    while (str[i] != '\0') {
        c = str[i];
        write(2, &c, 1);
        i++;
    }
    return (0);
}

char * moins (char * s1)
{
    char *s2 = malloc(sizeof(char) * my_strlen(s1));

    for (int i = 1; i < my_strlen(s1); i++) {
        s2[i-1] = s1[i];
    }
    return s2;
}

int error (char * s1)
{
    if (my_str_isnum(s1) == 0){
        return 1;
    }
    return 0;
}

int lenmax (char * s1, char * s2)
{
    if (my_strlen(s2) > my_strlen(s1))
        return my_strlen(s2) + 1;
    return my_strlen(s1) + 1;
}

void printres(char *res, int r, char mode)
{
    if (mode == '+')
        if (r != 0)
            my_putchar('1');
    if (mode == '-')
        if (r > 0)
            my_putchar('-');
    my_putstr(res);
}