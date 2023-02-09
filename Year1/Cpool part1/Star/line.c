/*
** EPITECH PROJECT, 2021
** line.c
** File description:
** linefile
*/

void print(int x, char c);

void line (unsigned int n)
{

    print(2*n+1, '*');
    if (n == 1) {
        print(1, ' ');
    }else{
        print(2*n-3, ' ');
    }
    print(2*n+1, '*');
    print(1, '\n');
}
