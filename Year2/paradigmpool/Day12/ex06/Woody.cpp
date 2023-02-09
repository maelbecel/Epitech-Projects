/*
** EPITECH PROJECT, 2023
** x
** File description:
** x
*/

#include "Woody.hpp"

Woody::Woody(const std::string name, const std::string file) : Toy(Toy::WOODY, name, file)
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std ::string text)
{
    std::cout << "WOODY: " << this->getName() << " \"" << text << "\"" << std::endl;
    return true;
}
