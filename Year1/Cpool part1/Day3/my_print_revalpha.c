/*
** EPITECH PROJECT, 2021
** my_print_revalpha.c
** File description:
** xxx
*/

int my_print_revalpha(void)
{
    int letter_prompt = 122;
    while ( letter_prompt >= 97){
        my_putchar(letter_prompt);
        letter_prompt--;
    }
}
