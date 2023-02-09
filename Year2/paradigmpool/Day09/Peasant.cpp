/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#include "Peasant.hpp"

bool Peasant::assertPower(int power)
{
    if (this->_hp <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return false;
    } else if (this->_power < power) {
        std::cout << this->_name << " is out of power." << std::endl;
        return false;
    }
    return true;
}

Peasant::Peasant ( const std :: string & name , int power ) : _name(name), _power(power), _hp(100)
{
    std::cout << this->_name << " goes for an adventure." << std::endl;
}

const std::string &Peasant::getName () const
{
    return this->_name;
}

int Peasant::getPower () const
{
    return this->_power;
}

int Peasant::getHp () const
{
    return this->_hp;
}

Peasant::~Peasant()
{
    std::cout << this->_name << " is back to his crops." << std::endl;
}

int Peasant::attack()
{
    if (!assertPower(10)) {
        return 0;
    }
    _power = (_power - 10 <= 0) ? 0 : _power - 10;;
    std::cout << this->_name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (!assertPower(0)) {
        return 0;
    }
    std::cout << this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (!assertPower(0)) {
        return;
    }
    _power = (_power + 30 > 100) ? 100 : _power + 30;
    std::cout << this->_name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    if (damage < _hp)
        std::cout << this->_name << " takes " << damage << " damage." << std::endl;
    else
        std::cout << this->_name << " is out of combat." << std::endl;
    _hp = (damage > _hp) ? 0 : _hp - damage;
}

void Peasant::drink(const IPotion &potion)
{
    int pow = potion.getPower();
    int health = potion.getHealth();
    std::cout << this->_name << " drinks a mysterious potion." << std::endl;
    if (health < 0)
        _hp = (_hp + health < 0) ? 0 : _hp + health;
    else
        _hp = (_hp + health > 100) ? 100 : _hp + health;
    _power = (_power + pow > 100) ? 100 : _power + pow;
}

void Peasant::drink(const HealthPotion &potion)
{
    int health = potion.getHealth();
    std::cout << this->_name << " feels rejuvenated." << std::endl;
    _hp = (_hp + health > 100) ? 100 : _hp + health;
}

void Peasant::drink(const PoisonPotion &potion)
{
    int health = potion.getHealth();
    std::cout << this->_name << " has been poisoned." << std::endl;
    _hp = (_hp + health < 0) ? 0 : _hp + health;
}

void Peasant::drink(const PowerPotion &potion)
{
    int pow = potion.getPower();
    std::cout << this->_name << "'s power is restored." << std::endl;
    _power = (_power + pow > 100) ? 100 : _power + pow;
}