/*
** EPITECH PROJECT, 2023
** k
** File description:
** k
*/

#include "Knight.hpp"

Knight::Knight( const std :: string & name , int power ) : Peasant(name, power)
{
    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->_name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (!assertPower(10)) {
        return 0;
    }
    _power -= 10;
    std::cout << this->_name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (!assertPower(30)) {
        return 0;
    }
    _power = (_power - 30 <= 0) ? 0 : _power - 30;
    std::cout << this->_name << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    if (!assertPower(0)) {
        return;
    }
    _power = (_power + 50 > 100) ? 100 : _power + 50;
    std::cout << this->_name << " eats." << std::endl;
}
