/*
** EPITECH PROJECT, 2023
** fruit
** File description:
** fruit
*/

#include "IFruit.hpp"

static std::string boolToString(bool boolean)
{
    return (boolean) ? "true" : "false";
}

std::ostream &operator<<(std::ostream &s, const IFruit &fruit)
{
    s << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << boolToString(fruit.isPeeled()) << "]";
    return s;
}

// std::ostream &operator<<(std::ostream &s, const IFruit const *&fruit)
// {
//     s << "[name: \"" << fruit->getName() << "\", vitamins: " << fruit->getVitamins() << ", peeled: " << boolToString(fruit->isPeeled()) << "]";
//     return s;
// }

