/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** str cat
*/

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int size = my_strlen(dest);

    my_strcpy(dest + size, src);
    return dest;
}
