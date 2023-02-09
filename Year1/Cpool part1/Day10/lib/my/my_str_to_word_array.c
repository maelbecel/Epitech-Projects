/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** xxx
*/

#include <stdlib.h>

int nbwords(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        while (my_char_isalpha(str[i]) == 0 && str[i])
            i++;
        while (my_char_isalpha(str[i]) == 1 && str[i])
            i++;
        if (my_char_isalpha(str[i - 1]) == 1)
            nb++;
    }
    return (nb);
}

int lenword(char const *str, int n)
{
    int i = 0;
    int len = 0;
    int word = 0;

    while (str[i]) {
        while (my_char_isalpha(str[i]) == 0 && str[i])
            i++;
        while (my_char_isalpha(str[i]) == 1 && str[i]) {
            i++;
            len++;
        }
        if (word == n)
            return (len + 1);
        i++;
        word++;
        len = 0;
    }
    return (0);
}

char **strtoword(char const *str, char **tab)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (str[i]) {
        while (my_char_isalpha(str[i]) == 0 && str[i])
            i++;
        while (my_char_isalpha(str[i]) == 1 && str[i]) {
            tab[x][y] = str[i];
            i++;
            y++;
        }
        while (my_char_isalpha(str[i]) == 0 && str[i])
            i++;
        tab[x][y] = '\0';
        y = 0;
        x++;
    }
    tab[x] = 0;
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    int nb_words;
    char **tab;
    int i = 0;

    if (str == 0)
        return (0);
    while (my_char_isalpha(str[i]) == 0 && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return (0);

    nb_words = nbwords(str);
    tab = malloc(nb_words * sizeof(char *));

    if (tab == 0)
        return (0);
    for (int j = 0; j < nb_words; j++) {
        tab[j] = malloc(lenword(str, j) * sizeof(char));
        }
    strtoword(str, tab);
    return (tab);
}
