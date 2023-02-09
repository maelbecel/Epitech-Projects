/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** getnbr
*/

int condi_nbr(char const *str, int *neg, int *condi, int i)
{
    if ((str[i + 1] < '0' || str[i + 1] > '9') && str[i + 1] != '\0')
        *condi = 0;
    if (i > 0 && str[i - 1] == '-')
        *neg = 1;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 0;
    int condi = 1;

    while (str[i] != '\0' && condi == 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (nb + (str[i] - '0')) * 10;
            condi_nbr(str, &neg, &condi, i);
        }
        i++;
    }
    if (neg == 1)
        nb = nb * (-1);
    return nb / 10;
}
