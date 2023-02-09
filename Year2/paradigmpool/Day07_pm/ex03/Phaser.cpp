/*
** EPITECH PROJECT, 2023
** Phaser
** File description:
** phaser
*/

#include "Phaser.hpp"

Phaser::Phaser(int x,  AmmoType type)
{
    this->_maxAmmo = x;
    this->_type = type;
    this->magazine[0] = 0;
    this->magazine[1] = 0;
    this->magazine[2] = 0;
    this->magazine[type] = x;
}

Phaser::~Phaser()
{
}

void Phaser::fire()
{
    if (this->magazine[this->_type] == 0) {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }
    if (this->_type == REGULAR)
        std::cout << Sounds::Regular << std::endl;
    if (this->_type == PLASMA)
        std::cout << Sounds::Plasma << std::endl;
    if (this->_type == ROCKET)
        std::cout << Sounds::Rocket << std::endl;
    this->magazine[this->_type]--;
}

void Phaser::ejectClip(void)
{
    this->magazine[this->_type] = 0;
}

void Phaser::changeType(AmmoType type)
{
    this->_type = type;
    if (type == REGULAR)
        std::cout << "Switching ammo to type: regular" << std::endl;
    if (type == PLASMA)
        std::cout << "Switching ammo to type: plasma" << std::endl;
    if (type == ROCKET)
        std::cout << "Switching ammo to type: rocket" << std::endl;
}

void Phaser::reload()
{
    std::cout << "Reloading ..." << std::endl;
    this->magazine[_type] = this->_maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    if (this->magazine[type] >= _maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    } else
        this->magazine[type]++;
}

int Phaser::getCurrentAmmos(void)
{
    return this->magazine[this->_type];
}
