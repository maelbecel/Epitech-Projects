/*
** EPITECH PROJECT, 2021
** rush.c
** File description:
** rush
*/

void print(int x, char c)
{
    int i = 0;
    while (i < x) {
        write (1, &c, 1);
        i++;
    }
}

void line_up (int x , int y )
{
    if (x > 1){
        print(1, '/');
        print(x-2, '*');
        print(1, 92);
        print(1, '\n');
    }
}

void line_down (int x , int y )
{
    if (x > 1){
        print(1, 92);
        print(x-2, '*');
        print(1, '/');
        print(1, '\n');
    }
}

void middle (int x , int y)
{
    int i = 0;
    for (i ; i < y-2 ; i++){
        print(1, '*');
        print(x-2, ' ');
        print(1, '*');
        print(1, '\n');
    }
}

void rush (int x , int y )
{
    if (x <= 0 || y <= 0){
        write(2, "Invalid size\n", 14);
    }
    if (x == 1 || y == 1){
        for (int i = 1 ; i <= y ; i++) {
            print(x, '*');
            print(1, '\n');
        }
    } else if (x > 0 || y > 0){
        line_up(x, y);
        middle(x, y);
        if (y > 1){
            line_down(x, y);
        }
    }
}
