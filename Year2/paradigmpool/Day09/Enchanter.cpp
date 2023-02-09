/*
** EPITECH PROJECT, 2023
** E
** File description:
** E
*/

#include "Enchanter.hpp"

Enchanter::Enchanter( const std :: string & name , int power ) : Peasant(name, power)
{
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (!assertPower(0)) {
        return 0;
    }
    std::cout << this->_name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (!assertPower(50)) {
        return 0;
    }
    _power = (_power - 50 <= 0) ? 0 : _power - 50;
    std::cout << this->_name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    if (!assertPower(0)) {
        return;
    }
    _power = 100;
    std::cout << this->_name << " meditates." << std::endl;
}

