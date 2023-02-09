/*
** EPITECH PROJECT, 2021
** strstr.c
** File description:
** strstr
*/

int my_strlen2( char const *str )
{
    int i = 0;
    while ( str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int x = 0;
    int lenfind = my_strlen2(to_find);
    int lenstr = my_strlen2(str);

    while (str[i] != '\0') {
        if (lenfind == 1 && str[i] == to_find[0]){
            return (to_find);
        }
        if (str[i] == to_find[x] && i == lenfind - 1)
            return (to_find);
        else if (str[i] == to_find[x] && x < lenfind)
            x++;
        else
            x = 0;
        i++;
    }
    return ("");
}