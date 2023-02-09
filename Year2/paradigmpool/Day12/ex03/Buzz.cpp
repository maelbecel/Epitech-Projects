/*
** EPITECH PROJECT, 2023
** bu
** File description:
** buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string name, const std::string file) : Toy(Toy::BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std ::string text)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << text << "\"" << std::endl;
}
