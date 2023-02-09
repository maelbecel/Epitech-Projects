/*
** EPITECH PROJECT, 2023
** skat
** File description:
** skat
*/

#include "Skat.hpp"

Skat::Skat (const std::string &name = "bob" ,int stimPaks = 15, int serial , int x , int y, Phaser :: AmmoType type) : _name(name), _steamPaks(stimPaks)
{
    _kreog = KreogCom(serial, x, y);
    _phaser = Phaser(20, type);
}

Skat::~Skat()
{
}

int &Skat::stimPaks(void)
{
    return _steamPaks;
}

const std::string &Skat::name(void)
{
    return _name;
}

void Skat::shareStimPaks (int number , int &stock )
{
    if (number > _steamPaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    _steamPaks -= number;
    stock += number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks( unsigned int number )
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _steamPaks += number;
}

void Skat::useStimPaks(void)
{
    if (_steamPaks == 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    _steamPaks -= 1;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}

void Skat::status(void)
{
    std::cout << "Soldier " << _name << " reporting " << _steamPaks << " stimpaks remaining sir!" << std::endl;
}