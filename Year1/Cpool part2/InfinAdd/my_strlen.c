/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** xxx
*/

int my_strlen( char const *str )
{
    int i = 0;
    while ( str[i] != '\0') {
        i++;
    }
    return (i);
}
