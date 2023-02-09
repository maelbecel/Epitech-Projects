/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** x
*/

int lenarray(char const *tab[])
{
    int i = 0;

    while (tab[i] != '\0') {
        i++;
    }
    return (i);
}

int my_sort_word_array( char ** tab )
{
    char *x;

    for (int i = 0; i < lenarray(tab) - 1; i++) {
        if (my_strcmp(tab[i], tab[i + 1]) < 0) {
            x = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = x;
            i = -1;
        }
    }
    return (0);
}
