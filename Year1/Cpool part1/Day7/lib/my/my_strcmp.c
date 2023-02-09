/*
** EPITECH PROJECT, 2021
** xxx
** File description:
** sxxx
*/

int my_strlen3( char const *str )
{
    int i = 0;

    while ( str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int s = 0;

    if (my_strlen3(s1) > my_strlen3(s2))
        return (my_strlen3(s1) - my_strlen3(s2));
    else if (my_strlen3(s1) < my_strlen3(s2))
        return (my_strlen3(s1) - my_strlen3(s2));
    for (i; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            s -=  1;
        else if (s1[i] > s2[i])
            s += 1;
    }
    return (s);
}
