/*
** EPITECH PROJECT, 2021
** test_my_strcpy.c
** File description:
** mystrcpy
*/

#include <criterion/criterion.h>

char *my_strncmp(char * s1, char *s2, int n);

Test(my_strncmp, test01)
{
    char str[6] = {0};

    strcpy(str, strdup("Hello"));
    cr_assert_eq(my_strncmp(str, "Hello", 5), 0);
}

Test(my_strncmp, test02)
{
    char str[6] = {0};
    strcpy(str, strdup("Hello"));

    cr_assert_eq(my_strncmp(str, "Hellop",3), 0);
}
