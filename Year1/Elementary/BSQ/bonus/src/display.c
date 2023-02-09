/*
** EPITECH PROJECT, 2021
** display.C
** File description:
** display
*/

#include "bsq.h"
#include "my.h"

void print(int x, char c);
void print_slash (int i, int x);
void print_wall (int x);
void add_right (int space, int r, char *str);
void rush (int x, int y, int z);

void print(int x, char c)
{
    int i = 0;
    while (i < x) {
        write (1, &c, 1);
        i++;
    }
}

void print_slash (int i, int x)
{
    print(i, ' ');
    print(1, '/');
    print(x-2, ' ');
    print(1, '/');
}

void print_wall (int x)
{
    print(1, '|');
    print(x-2, ' ');
    print(1, '|');
}

void add_right (int space, int r, char *str)
{
    print(space, ' ');
    print(1, str[r]);
    print(1, '\n');
}

void display_cube (int x, int y, int z)
{
    print(z+1, ' ');
    line(x);
    print(1, '\n');
    int r = 0;
    char str[y+z-2];
    int space = -1;
    right(x, y, z, str);

    for (int i = z ; i >= 1 ; i--){
        print_slash(i, x);
        if (str[r] == '|' || str[r] == 'o')
            space++;
        add_right(space, r, str);
        r++;
    }
    line(x);
    if (str[r] == '|' || str[r] == 'o')
        space++;
    add_right(space, r, str);
    r++;
    for (int j = 0 ; j < y-2 ; j++){
        print_wall(x);
        if (str[r] == '|' || str[r] == 'o'){
            space;
        }else
            space--;
        add_right(space, r, str);
        r++;
    }
    line(x);
}

void display (Point *maxsquare, Len *square, char *buffer)
{
    my_putstr("Base cube is :\n");
    if (square->col + square->dimensions > 250)
        my_putstr("\n[cube too big to be displayed]");
    else
        display_cube(square->col + 2, square->line/2 + 2, square->dimensions/2);
    my_putstr("\n\n");
    my_putstr("Biggest cube is in ");
    my_putstr("x = ");
    my_put_nbr(maxsquare->x);
    my_putstr(", y = ");
    my_put_nbr(maxsquare->y);
    my_putstr(", z = ");
    my_put_nbr(maxsquare->z);
    my_putstr(" and of size ");
    my_put_nbr(maxsquare->size);
    my_putstr(" :\n");
    if (maxsquare->size * 2 > 250)
        my_putstr("\n[cube too big to be displayed]");
    else
        display_cube(maxsquare->size + 2, maxsquare->size/2 + 2, maxsquare->size/2);
    my_putstr("\n");
}