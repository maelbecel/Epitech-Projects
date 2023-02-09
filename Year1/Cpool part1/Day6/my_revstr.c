/*
** EPITECH PROJECT, 2021
** test_my_revstr.c
** File description:
** myrevstr
*/

int my_strlen( char const *str )
{
    int i = 0;
    while ( str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char temp;
    int first = 0;
    int last = my_strlen(str) - 1;

    while (first < last) {
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;
        first++;
        last--;
    }
    return (str);
}
