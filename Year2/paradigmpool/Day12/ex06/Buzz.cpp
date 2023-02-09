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

bool Buzz::speak(const std ::string text)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << text << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std ::string text)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << text << "\" senorita" << std::endl;
    return true;
}
