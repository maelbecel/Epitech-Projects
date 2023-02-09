/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "DroidMemory.hpp"
#include "Droid.hpp"
#include <iostream>

int main ()
{
    srand(42);
    DroidMemory mem1 ;
    Droid d1 = Droid("Rudolf");
    Droid d2 = Droid("Gaston");
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    if (d1 == d2)
        std::cout << "Droids are the same" << std::endl;
    else
        std::cout << "Droids are not the same" << std::endl;
    std::cout << mem1 << std::endl;
}