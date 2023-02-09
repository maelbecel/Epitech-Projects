/*
** EPITECH PROJECT, 2021
** cat.c
** file description:
** xxx
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main (int ac, char ** argv);

Test (name , Test01)
{
	system("../cat ./cat bonjour.txt");
	cr_expect_stdout_eq_str("Bonjour");
}
