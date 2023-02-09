/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it.c
** File description:
** xxx
*/

int my_compute_factorial_rec(int nb )
{
    if (nb < 0 || nb >= 13) {
        return 0;
    } else if (nb == 0){
        return 1;
    } else {
        return nb *= my_compute_factorial_rec(nb - 1);
    }
}
