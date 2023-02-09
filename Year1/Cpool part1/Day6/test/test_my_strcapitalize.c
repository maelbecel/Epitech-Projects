/*
** EPITECH PROJECT, 2021
** test_my_strcpy.c
** File description:
** mystrcpy
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char * str);

Test(my_strcapitalize, test01)
{
    char *x = strdup("hey, how are you? 42WORds forty-two; fifty+one");
    char *y = strdup("Hey, How Are You? 42words Forty-Two; Fifty+One");
    cr_assert_str_eq(my_strcapitalize(x), y);
}
