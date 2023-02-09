/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <unistd.h>
void rush (int x , int y , int z);
void print(int x, char c);

int main ()
{
    for (int x = 0; x < 6; x++){
        for (int y = 2; y < 6; y++){
            for (int z = 0; z <6; z++){
                rush(x,y,z);
                print(3, '\n');
            }
        }
    }

    rush(20,10,5);
    return (0) ;
}
