/*
** EPITECH PROJECT, 2021
** test_my_strcpy.c
** File description:
** mystrcpy
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_revstr, test1)
{
    char dest[6] = {0};
    char c[] = "coucou";
    my_strncpy(dest, c, 6);
    cr_assert_str_eq (dest, "coucou");
}

Test(my_revstr, test2)
{
    char dest[13] = {0};
    char c[] = "Salut a tous";
    my_strncpy(dest, c, 1);
    cr_assert_str_eq (dest, "S");
}

Test(my_revstr, test3)
{
    char dest[6] = {0};
    char c[] = "sgg<";
    my_strncpy(dest, c, 0);
    cr_assert_str_eq (dest, "");
}
