/*
** EPITECH PROJECT, 2021
** my_is_prime_sup.c
** File description:
** xxx
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int i = nb ; 1 ; i++) {
        if (my_is_prime(i)) {
            return i;
        }
    }
}
