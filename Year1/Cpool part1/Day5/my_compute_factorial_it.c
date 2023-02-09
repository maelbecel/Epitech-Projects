/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it.c
** File description:
** xxx
*/

int my_compute_factorial_it(int nb )
{
    if (nb < 0 || nb >= 13) {
        return 0;
    }
    if (nb == 0){
        return 1;
    }
    int x = 1;
    for (int i = nb ; i > 0 ; i--){
        x *= i;
    }
    return x;
}
