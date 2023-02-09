/*
** EPITECH PROJECT, 2021
** test_my_strcpy.c
** File description:
** mystrcpy
*/

#include <criterion/criterion.h>

char *my_revstr(char *);

Test(my_revstr, return_value_is_reversed)
{
    char str[6] = {0};

    strcpy(str, strdup("Hello"));
    cr_assert_str_eq(my_revstr(str), strdup("olleH"));
}
