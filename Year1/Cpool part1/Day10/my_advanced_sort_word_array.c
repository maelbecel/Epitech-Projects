/*
** EPITECH PROJECT, 2021
** my_advanced_sort_int_array
** File description:
** x
*/

int lenarray(char const *tab[]);

int my_advanced_sort_word_array (char ** tab ,
                                 int (* cmp ) ( char const * , char const *) )
{
    char *x;

    for (int i = 0; i < lenarray(tab) - 1; i++) {
        if (cmp(tab[i], tab[i + 1]) < 0) {
            x = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = x;
            i = -1;
        }
    }
    return (0);
}
