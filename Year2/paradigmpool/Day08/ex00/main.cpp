/*
** EPITECH PROJECT, 2023
** droid
** File description:
** droid
*/

#include "Droid.hpp"

int main ()
{
    Droid d;
    d.setStatus(new std::string("Kill Kill Kill!"));
    Droid d2 = d;
    d.setStatus(new std::string("Kill Kill Kill!"));
    if ((d2 != d) || !(d2 == d))
        std::cout << "Fail! All of us want to kill!" << std::endl;
    return 0;
}