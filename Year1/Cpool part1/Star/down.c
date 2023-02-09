/*
** EPITECH PROJECT, 2021
** down.c
** File description:
** downfile
*/

void print(int x, char c);

void down_1 ( void )
{
    print(3, ' ');
    print(1, '*');
    print(1, '\n');
}

void down_boucle(int spacebefore, int spaceunder)
{
    print(spacebefore, ' ');
    print(1, '*');
    print(spaceunder, ' ');
    print(1, '*');
    print(1, '\n');
}

void down (unsigned int n)
{
    if (n == 1) {
        down_1();
    }else{
        int spacebefore = 2*n;
        int spaceunder = 2*n-3;
        int i = 0;
        while ( i <= n-2) {
            down_boucle(spacebefore, spaceunder);
            spacebefore++;
            spaceunder -= 2;
            i++;
        }
        print(2*n+(n-1), ' ');
        print(1, '*');
        print(1, '\n');
    }
}
