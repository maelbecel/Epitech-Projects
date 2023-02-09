/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** strncmpx
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    char cmp1 = 0;
    char cmp2 = 0;
    int i = 0;
    int result = 0;

    while (cmp1 == cmp2 && i < n) {
        cmp1 = s1[i];
        cmp2 = s2[i];
        i++;
    }
    result = cmp1 - cmp2;
    return result;
}
