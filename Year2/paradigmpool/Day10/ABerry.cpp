/*
** EPITECH PROJECT, 2023
** aberry
** File description:
** berry
*/

#include "ABerry.hpp"

ABerry::ABerry(std::string name, unsigned int vitamines) : AFruit(name, vitamines)
{
    peel();
}

ABerry::~ABerry()
{
}
