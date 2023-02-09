/*
** EPITECH PROJECT, 2021
** top.c
** File description:
** topfile
*/

void print(int x, char c);

void top_1( void )
{
    print (3, ' ');
    print (1, '*');
    print(1, '\n');
}

void top_print(int spacebefore , int spaceunder)
{
    print (spacebefore, ' ');
    print (1, '*');
    print (spaceunder, ' ');
    print (1, '*');
    print (1, '\n');
}

void top (unsigned int n)
{
    int spaceunder;
    int spacebefore;
    int i;
    if (n == 1) {
        top_1();
    } else {
        spacebefore = 2*n+(n-1);
        spaceunder = 0;
        print (spacebefore, ' ');
        print (1, '*');
        print (1, '\n');
        spacebefore--;
        spaceunder += 1;
        i = 0;
        while (i < n-1) {
            top_print(spacebefore, spaceunder);
            spacebefore--;
            spaceunder += 2;
            i++;
        }
    }
}
