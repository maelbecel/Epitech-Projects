/*
** EPITECH PROJECT, 2021
** my_print_comb.c
** File description:
** xxx
*/

void my_putchar(char c);

int print_num(int cent , int dix , int un)
{
    if (cent < dix && dix < un) {
        my_putchar(cent);
        my_putchar(dix);
        my_putchar(un);
        if (cent != '7' || dix != '8' || un != '9') {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb( void )
{
    int cent;
    int dix;
    int un;

    for (cent = '0'; cent <= '7' ; cent++){
        for (dix = '0'; dix <= '8' ; dix++){
            for (un = '0' ; un <= '9' ; un++){
                print_num(cent,dix,un);
            }
        }
    }
}
