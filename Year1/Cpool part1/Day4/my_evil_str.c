/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** xxx
*/

void my_putchar(char c);

int len ( char *str )
{
    int i = 0;
    while ( str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_evil_str(char *str )
{
    int l = len(str)-1;
    char c;
    for (int i = 0; i < l / 2; i++ ){
        c = str[i];
        str[i] = str[l - i];
        str[l - i] = c;
    }
    return (str);
}
