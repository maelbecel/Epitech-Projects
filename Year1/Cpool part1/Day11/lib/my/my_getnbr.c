/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** xxx
*/

int my_getnbr(char const *str)
{
    int n = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            n *= 10;
            n += str[i] - '0';
        } else {
            return 0;
        }
    i++;
    }
    return n;
}
