/*
** EPITECH PROJECT, 2021
** test_my_strcpy.c
** File description:
** mystrcpy
*/

#include <criterion/criterion.h>

char *my_strstr(char * str, char const *to_find);

Test(my_strstr, test01)
{
    char str[6] = {0};

    strcpy(str, strdup("Hello"));
    cr_assert_str_eq(my_strstr(str, "Hello"), strdup("Hello"));
}

Test(my_strstr, test02)
{
    char str[6] = {0};

    strcpy(str, strdup("Hello"));
    cr_assert_str_eq(my_strstr(str, "ello"), strdup("ello"));
}

Test(my_strstr, test03)
{
    char str[6] = {0};

    strcpy(str, strdup("Hello"));
    cr_assert_str_eq(my_strstr(str,"Hl"), strdup(""));
}
