/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** xxx
*/

int *my_str_isupper(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 'A' || str[i] >= 'Z') {
            return 0;
        }
        i++;
    }
    return 1;
}
