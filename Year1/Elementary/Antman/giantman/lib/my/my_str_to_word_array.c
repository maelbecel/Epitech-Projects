/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_putstr(char const *str);

int is_alpha_num(char a)
{
    int is_alpha = (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
    int is_num = (a >= '0' && a <= '9');

    return (is_alpha || is_num);
}

int count_words(char const *str)
{
    int nb_words = 0;
    int is_next_num = 0;
    int is_next_end = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        is_next_num = (is_alpha_num(str[i]) && (!is_alpha_num(str[i + 1])));
        is_next_end = (is_alpha_num(str[i]) && str[i + 1] == '\0');
        if (is_next_num || is_next_end)
            nb_words++;
    }
    return nb_words;
}

char *fill_array(char const *str, int i)
{
    char *dest;
    int j = 0;
    int len = 0;

    while (is_alpha_num(str[i])) {
        i++;
        len++;
    }
    dest = malloc(sizeof(char) * (len));
    dest[len] = '\0';
    while (j < len) {
        dest[j] = str[i - len];
        j++;
        i++;
    }
    return dest;
}

char **my_str_to_word_array(char const *str)
{
    int nb_words = 0;
    int j = 0;
    char **arr;

    if (str == NULL){
        arr = malloc(sizeof(char *) * 1);
        arr[0] = NULL;
        return arr;
    }
    nb_words = count_words(str);
    arr = malloc(sizeof(char *) * (nb_words + 1));
    arr[nb_words] = NULL;
    for (int i = 0; str[i] != '\0' && j < nb_words;) {
        while (!is_alpha_num(str[i++]));
        arr[j] = fill_array(str, i - 1);
        j++;
        while (is_alpha_num(str[i++]));
    }
    return arr;
}
