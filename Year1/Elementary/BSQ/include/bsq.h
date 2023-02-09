/*
** EPITECH PROJECT, 2021
** bsq.h
** File description:
** bsq.h
*/

#ifndef bsq
#define bsq

typedef struct Point Point;
struct Point {
    int x;
    int y;
    int size;
};

typedef struct Len Len;
struct Len {
    int col;
    int line;
};

int decal(char *str);
int *buffer_to_matrix(char *str, Len *square);
int get_lower(int x, int y, int *map, Len *square);
int check_square(int x, int y, int *map, Len *square);
void max_square(Point *maxsquare, Len *square, int *map);
void display (Point *maxsquare, Len *square, char *buffer);

#endif
