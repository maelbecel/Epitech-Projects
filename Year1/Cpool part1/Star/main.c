/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** 
*/


#include <stdio.h>

void star (unsigned int n);
void top (unsigned int n);
void down (unsigned int n);
void mid (unsigned int n);
void line (unsigned int n);
void print (int x, char c);



int launch ()
{
	printf("\033[0;36m");
	printf("\n");
	star(5);
}

int main (int argc)
{
	launch();
	return('0');
}
