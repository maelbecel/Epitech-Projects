/*
** EPITECH PROJECT, 2023
** Priest
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std :: string & name , int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << _name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;

}

void Priest::rest()
{
    if (!assertPower(0)) {
        return;
    }
    _power = 100;
    _hp = 100;
    std::cout << this->_name << " prays." << std::endl;
}