/*
** EPITECH PROJECT, 2021
** detection.c
** File description:
** detection
*/

#include "my.h"
#include <stdlib.h>

int calcul(int nb1, char signe, int nb2)
{
    switch (signe){
        case '+': return nb1 + nb2;
        case '-': return nb1 - nb2;
        case '*': return nb1 * nb2;
        case '/': return nb1 / nb2;
        case '%': return nb1 % nb2;
    }
}

int my_intstrlen(char *str)
{
    int i = 0;
    int breakwhile = 1;

    if (str[i] == '-')
        i++;

    while (str[i] != '\0' && breakwhile == 1) {
        if (str[i] < '0' || str[i] > '9') {
            breakwhile = 0;
        }
        i++;
    }
    return i - 1;
}

int detection(char *av)
{
    char signe;
    int nb1 = 0;
    int nb2 = 0;
    int sizestr1 = my_intstrlen(av);

    if (unvalidinput(av) == 1)
        return 84;
    nb1 = my_getnbr(av);
    signe = av[sizestr1];
    nb2 = my_getnbr(av + sizestr1 +1);
    return calcul(nb1, signe, nb2);
}
