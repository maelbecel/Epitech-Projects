/*
** EPITECH PROJECT, 2023
** toy
** File description:
** roy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _ascii.data = "";
}

Toy::~Toy()
{
}

Toy::Toy(ToyType type, const std::string name, const std::string &filename)
{
    _type = type;
    _name = name;
    _ascii.getPictureFromFile(filename);
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string file)
{
    return _ascii.getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return _ascii.data;
}