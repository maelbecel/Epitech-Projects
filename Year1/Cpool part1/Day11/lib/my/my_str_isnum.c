/*
** EPITECH PROJECT, 2021
** my_strisnum
** File description:
** xxx
*/

int *my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= '0' || str[i] >= '9') {
            return 0;
        }
        i++;
    }
    return 1;
}
