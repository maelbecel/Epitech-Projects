/*
** EPITECH PROJECT, 2021
** my_print_comb2.c
** File description:
** 
*/
void my_putchar(char c);

int print_num2(int nb1 , int nb2 , int nb3 , int nb4)
{
    my_putchar(nb1);
    my_putchar(nb2);
    my_putchar(' ');
    my_putchar(nb3);
    my_putchar(nb4);
    if(nb1 != '9' || nb2 != '8' || nb3 != '9' || nb4 != '9') {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb2( void )
{
    int nb1 = '0';
    int nb2 = '0';
    int nb3 = '0';
    int nb4 = '1';

    while (nb1 <= '9' && nb2 <= '9' && nb3 <= '9' && nb4 <= '9') {
        if(nb2 >= '9' && nb3 >= '9' && nb4 >= '9'){
            nb1++;
            nb2 = '0';
            nb3 = nb1 + 1;
            nb4 = nb2 + 1;
        }
        if(nb3 >= '9' && nb4 >= '9'){
            nb2++;
            nb3 = nb1;
            nb4 = nb2;
        }
        if(nb4 >= '9'){
            nb3++;
            nb4 = '0';
        }
        if (nb1 >= '9') {
            nb3 = '9';
        }
        else{
            nb4++;
        }
        print_num2(nb1, nb2, nb3, nb4);
    }
}
