/*
** EPITECH PROJECT, 2021
** mid.c
** File description:
** midfile
*/

void print(int x, char c);

void mid_1 ( void )
{
    print(1, ' ');
    print(1, '*');
    print(3, ' ');
    print(1, '*');
    print(1, '\n');
}

void mid_reduce ( int spacebefore, int spaceunder)
{
    print (spacebefore, ' ');
    print (1, '*');
    print (spaceunder, ' ');
    print (1, '*');
    print (1, '\n');
}


int mid (unsigned int n)
{
    int diametre = 6*n-1;
    int spacebefore = 1;
    int spaceunder = diametre-2-2*spacebefore;
    if (n == 1) {
        mid_1();
        return (0);
    }
    for (int i = 0 ; i < n; i++) {
        mid_reduce(spacebefore, spaceunder);
        spacebefore ++;
        spaceunder -= 2;
    }
    spacebefore -= 2;
    spaceunder += 4;
    for (int i = 0 ; i < n-1; i++) {
        mid_reduce(spacebefore, spaceunder);
        spacebefore --;
        spaceunder += 2;
    }
}
