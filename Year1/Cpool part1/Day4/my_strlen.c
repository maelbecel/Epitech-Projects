/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** xxx
*/

void my_putchar(char c);

int my_strlen( char const *str )
{
    int i = 0;
    while ( str[i] != '\0') {
        i++;
    }
    return (i);
}
