/*
** EPITECH PROJECT, 2023
** f
** File description:
** f
*/

#include "FruitFactory.hpp"

FruitFactory::FruitFactory()
{
}

FruitFactory::~FruitFactory()
{
}

void FruitFactory::registerFruit ( IFruit * fruit )
{
    for (int i = 0; (size_t)i < _reg.size(); i++) {
        if (fruit->getName() == _reg[i]->getName()) {
            _reg[i] = fruit->clone();
            return;
        }
    }
    _reg.push_back(fruit->clone());
}

void FruitFactory::unregisterFruit ( const std :: string & name )
{
    for (int i = 0; (size_t)i < _reg.size(); i++) {
        if (name == _reg[i]->getName()) {
            _reg.erase(_reg.begin() + i);
            return;
        }
    }
}

IFruit *FruitFactory::createFruit(const std::string &name) const
{
    for (int i = 0; (size_t)i < _reg.size(); i++) {
        if (name == _reg[i]->getName()) {
            return _reg[i]->clone();
        }
    }
    return nullptr;
}
