/*
** EPITECH PROJECT, 2021
** rush.c
** File description:
** rush
*/

#include <stdlib.h>

void lastcase(int larg, int haut)
{
    my_putstr("[rush1-3] ");
    my_put_nbr(larg);
    my_putchar(' ');
    my_put_nbr(haut);
    my_putstr(" || [rush1-4] ");
    my_put_nbr(larg);
    my_putchar(' ');
    my_put_nbr(haut);
    my_putstr(" || [rush1-5] ");
    my_put_nbr(larg);
    my_putchar(' ');
    my_put_nbr(haut);
    my_putchar('\n');
}

void firstcase(char *av, int larg, int haut)
{
    if (av[0] == 'o') {
        my_putstr("[rush1-1] ");
        my_put_nbr(larg);
        my_putchar(' ');
        my_put_nbr(haut);
        my_putchar('\n');
    } else if (av[0] == '*') {
        my_putstr("[rush1-2] ");
        my_put_nbr(larg);
        my_putchar(' ');
        my_put_nbr(haut);
        my_putchar('\n');
    } else {
        if (av[0] == 'B'){
            lastcase(larg,haut);
        } else {
            write(2,"none\n",6);
        }
    }
}

char *getline (char *av, int larg, int haut)
{
    int first = (larg + 1)  * (haut - 1);
    int j = 0;
    char *line = malloc(my_strlen(av) + 1);
    char res[3];
    for (int i = first; i < first + larg; i++) {
        line[j] = av[i];
        j++;
    }
    line[j] = '\0';
    res[0] = line[0];
    res[1] = line[my_strlen(line)-1];
    res[2] = '\0';
    if (res[0] == 'o')
        return "[rush1-1] ";
    if (res[0] == 'A')
        return "[rush1-4] ";
    if (res[1] == '/')
        return "[rush1-2] ";
    if (res[0] == 'C') {
        if (res[1] == 'A')
            return "[rush1-5] ";
        else if (res[1] == 'C')
            return "[rush1-3] ";
    }
    return "none";
}

int rush3(char *av)
{
    int larg = 0;
    int haut = 0;
    char *file = malloc(my_strlen(av));
    if (my_strlen(av) == 0)
        return 84;
    for (int i = 0; av[i] != '\n'; i++) {
        larg += 1;
    }
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == '\n')
            haut += 1;
    }
    if (larg == 1 || haut == 1)
        firstcase(av, larg, haut);
    else {
        file = getline(av, larg, haut);
        if (file == "none"){
            write(2,"none\n",6);
            return 84;
        }
        my_putstr(file);
        my_put_nbr(larg);
        my_putchar(' ');
        my_put_nbr(haut);
        my_putchar('\n');
    }
    return 0;
}
