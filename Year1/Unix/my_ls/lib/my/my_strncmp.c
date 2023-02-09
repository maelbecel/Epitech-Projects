/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int i = (s1[0] == '.') ? 1 : 0;
    int j = (s2[0] == '.') ? 1 : 0;
    char a;
    char b;
    while (i < n && j < n) {
        a = (s1[i] < 97) ? s1[i] + 32 : s1[i];
        b = (s2[j] < 97) ? s2[j] + 32 : s2[j];
        if (a != b) {
            return (a - b);
        }
        j++;
        i++;
    }
    return (0);
}
