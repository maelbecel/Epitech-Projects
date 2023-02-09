/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** xxx
*/

void my_putchar(char c);
void my_putstr(char * x);

int my_show_word_array ( char * const * tab )
{
    int i = 0;
    while (tab[i] != '\0') {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}