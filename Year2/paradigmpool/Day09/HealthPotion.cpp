/*
** EPITECH PROJECT, 2023
** health
** File description:
** health
*/

#include "HealthPotion.hpp"

int HealthPotion::getHealth() const
{
    return this->_health;
}

int HealthPotion::getPower() const
{
    return this->_power;
}

HealthPotion::HealthPotion()
{
}

HealthPotion::~HealthPotion()
{
}
