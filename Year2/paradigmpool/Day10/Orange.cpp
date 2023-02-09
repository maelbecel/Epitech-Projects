/*
** EPITECH PROJECT, 2023
** orange
** File description:
** orange
*/

#include "Orange.hpp"

Orange::Orange() : ACitrus("orange", 7)
{
}

Orange::~Orange()
{
}

Orange::Orange(std::string name, unsigned int vitamine) : ACitrus(name, vitamine)
{
}
