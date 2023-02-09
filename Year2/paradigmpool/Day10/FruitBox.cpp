/*
** EPITECH PROJECT, 2023
** frout
** File description:
** frout
*/

#include "FruitBox.hpp"

static std::string boolToString(bool boolean)
{
    return (boolean) ? "true" : "false";
}

FruitBox::FruitBox(unsigned int size)
{
    this->_size = size;
}

FruitBox::~FruitBox()
{
    while (!_fruits.empty()) {
        delete _fruits.front();
        _fruits.pop_front();
    }
}

unsigned int FruitBox::getSize() const
{
    return this->_size;
}

unsigned int FruitBox::nbFruits() const
{
    return _fruits.size();
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (this->_size == this->nbFruits())
        return false;
    _fruits.push_back(fruit);
    return true;
}

IFruit *FruitBox::popFruit()
{
    IFruit *tmp;

    if (_fruits.empty())
        return nullptr;
    tmp = _fruits.front();
    _fruits.pop_front();
    return tmp;
}

std::deque <IFruit *>FruitBox::getQueue() const
{
    return this->_fruits;
}

void FruitBox::setQueue(std::deque <IFruit *> queue)
{
    this->_fruits = queue;
}

std::ostream &operator<<(std::ostream &s, const FruitBox &fruitbox)
{
    std::deque <IFruit *> fruits = fruitbox.getQueue();
    s << "[";
    for (IFruit *fruit : fruits) {
        s << "[name: \"" << fruit->getName() << "\", vitamins: " << fruit->getVitamins() << ", peeled: " << boolToString(fruit->isPeeled()) << "]";
        if (fruit != fruits.back())
            s << ", ";
    }
    s << "]";
    return s;
}