/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** xxx
*/

int my_compute_square_root (int nb)
{
    int impair = 1;
    int total = 0;
    int x = 0;
    while (total <= nb) {
        impair += 2;
        total += impair;
        x++;
    }
    if (x * x == nb){
        return x;
    } else {
        return 0;
    }
}
