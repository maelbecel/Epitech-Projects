/*
** EPITECH PROJECT, 2021
** print.c
** File description:
** printfile
*/

void print(int x, char c);
void print_slash (int i, int x);
void print_wall (int x);
void add_right (int space, int r, char *str);
void rush (int x, int y, int z);

void line (int x)
{
    print(1, 'o');
    print(x-2, '-');
    print(1, 'o');
}

void between (int z, int x)
{
    for (int i = z ; i >= 1 ; i--){
        print(i, ' ');
        print(1, '/');
        print(x-2, ' ');
        print(1, '/');
        print(1, '\n');
    }
}

void middle (int x , int y)
{
    int i = 0;

    for (i ; i < y-2 ; i++){
        print(1, '|');
        print(x-2, ' ');
        print(1, '|');
        print(1, '\n');
    }
}

char *right (int x, int y, int z, char *str)
{
    for (int i = 0 ; i <= y+z-1; i++){
        if (i < y-2){
            str[i] = '|';
        }else if (i == y-2){
            str[i] = 'o';
        }else{
            str[i] = '/';
        }
    }
    return str;
}