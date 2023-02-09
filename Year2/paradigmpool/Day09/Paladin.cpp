/*
** EPITECH PROJECT, 2023
** pal
** File description:
** pal
*/

#include "Paladin.hpp"

Paladin::Paladin(const std :: string & name , int power) : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    std::cout << name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << Peasant::getName() << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return (Knight::attack());
}

int Paladin::special()
{
    return (Enchanter::special());
}

void Paladin::rest()
{
    Priest::rest();
}
