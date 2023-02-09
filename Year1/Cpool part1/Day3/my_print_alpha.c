/*
** EPITECH PROJECT, 2021
** my_print_alpha.c
** File description:
** xxx
*/

int my_print_alpha(void)
{
    int letter_prompt = 97;
    while ( letter_prompt <= 122){
        my_putchar(letter_prompt);
        letter_prompt++;
    }
}

int my_print_alpha(void)
{
    for (char i = 'a'; i <= 'z'; my_putchar(i++));
}
