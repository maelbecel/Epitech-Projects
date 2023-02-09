/*
** EPITECH PROJECT, 2021
** my_compute_power_it.c
** File description:
** xxx
*/

int    my_compute_power_rec(int nb, int p)
{
    long res = 0;
    int max = 2147483647;
    if (p < 0) {
        return (0);
    } else if (p == 0) {
        return (1);
    } else {
        res = nb * my_compute_power_rec(nb, p - 1);
    }
    if (res > max || res < max*-1){
        return 0;
    }
    int sol = res;
    return (sol);
}
