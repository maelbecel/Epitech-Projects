/*
** EPITECH PROJECT, 2023
** fruit
** File description:
** fruit
*/

#include "AFruit.hpp"

AFruit::AFruit()
{
}

AFruit::AFruit(std::string name, unsigned int vitamins, bool peeled) : _isPeeled(peeled), _vitamins(vitamins), _name(name)
{
}

AFruit::AFruit(std::string name, unsigned int vitamins) : _isPeeled(false), _vitamins(vitamins), _name(name)
{
}


unsigned int AFruit::getVitamins() const
{
    return (isPeeled()) ? _vitamins : 0;
}

std::string AFruit::getName() const
{
    return _name;
}

bool AFruit::isPeeled() const
{
    return _isPeeled;
}

void AFruit::peel()
{
    _isPeeled = true;
}

void AFruit::setVitamins(unsigned int vitamins)
{
    _vitamins = vitamins;
}

void AFruit::setName(const std::string &name)
{
    _name = name;
}

AFruit::AFruit(IFruit &fruit)
{
    this->_name = fruit.getName();
    this->_vitamins = fruit.getVitamins();
    this->_isPeeled = fruit.isPeeled();
}

IFruit *AFruit::clone() const
{
    return new AFruit(*this);
}