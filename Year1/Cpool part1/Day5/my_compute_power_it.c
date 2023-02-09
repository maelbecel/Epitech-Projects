/*
** EPITECH PROJECT, 2021
** my_compute_power_it.c
** File description:
** xxx
*/

int my_compute_power_it(int nb, int p)
{
    long res = 1;
    int max = 2147483647;
    int sol;
    if (p < 0) {
        return (0);
    }
    while (p >= 1) {
        res *= nb;
        p = p - 1;
    }
    if (res > max || res < max*-1){
        return 0;
    }
    sol = res;
    return (sol);
}
