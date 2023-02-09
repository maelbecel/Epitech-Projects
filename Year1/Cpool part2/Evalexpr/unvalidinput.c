/*
** EPITECH PROJECT, 2021
** detection.c
** File description:
** detection
*/

#include "my.h"

int unvalidinput(char *av)
{
	for (int i = 0; av[i] != '\0'; i++){
		if ((av[i] > '9' || av[i] < '0') &&
			av[i] != '+' &&
			av[i] != '-' &&
			av[i] != '*' &&
			av[i] != '/' &&
			av[i] != '%' &&
			av[i] != '(' &&
			av[i] != ')')
			return 1;
	}
	return 0;
}
