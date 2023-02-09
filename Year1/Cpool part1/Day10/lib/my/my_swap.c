/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** xxx
*/

void my_swap(int *a , int * b )
{
    int swap = *b;
    *b = *a;
    *a = swap;
}
