/*
** EPITECH PROJECT, 2021
** rush_bonus.c
** File description:
** bonus
*/

#include <stdio.h>

void line (int x);
void between (int z, int x);
void middle (int x , int y);
char *right (int x, int y, int z, char *str);

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

void rush (int x, int y, int z)
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
