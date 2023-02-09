/*
** EPITECH PROJECT, 2021
** nbnumber.c
** File description:
** nombre de nombre
*/

int waitnum(int i, char *calcul, char *base)
{
    while (charinarray(calcul[i], base) == 1){
        i++;
    }
    return i;
}

int nbnumber(char *calcul, char *base, char *baseop)
{
    int nb = 0;

    for (int i = 0; calcul[i] != '\0'; i++) {
        if (charinarray(calcul[i], base) == 1){
            i = waitnum(i, calcul, base);
            nb++;
        }
    }
    return nb;
}