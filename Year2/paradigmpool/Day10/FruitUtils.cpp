/*
** EPITECH PROJECT, 2023
** fruit
** File description:
** fruit
*/

#include "FruitUtils.hpp"


FruitUtils::FruitUtils()
{
}

FruitUtils::~FruitUtils()
{
}

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry)
{
    std::deque <IFruit *> fruits = unsorted.getQueue();
    std::deque <IFruit *> newunsorted;

    while(!fruits.empty()) {
        IFruit *fruit = fruits.front();
        fruits.pop_front();
        if (dynamic_cast<Lemon *>(fruit) != nullptr)
            (!lemon.pushFruit(fruit)) ? newunsorted.push_back(fruit) : (void)0;
        else if (dynamic_cast<ACitrus *>(fruit) != nullptr)
            (!citrus.pushFruit(fruit)) ? newunsorted.push_back(fruit) : (void)0;
        else if (dynamic_cast<ABerry *>(fruit) != nullptr)
            (!berry.pushFruit(fruit)) ? newunsorted.push_back(fruit) : (void)0;
        else
            newunsorted.push_back(fruit);
    }
    unsorted.setQueue(newunsorted);
}

FruitBox **FruitUtils::pack(IFruit **fruits, unsigned int boxSize)
{
    int nbFruits = 0;
    int nbBoxes = 0;
    FruitBox **boxes;

    for (int i = 0; fruits[i]; i++)
        nbFruits++;
    nbBoxes = (nbFruits / boxSize);
    nbBoxes = ((nbBoxes * (int)boxSize) < nbFruits) ? nbBoxes + 1 : nbBoxes;
    boxes = new FruitBox *[nbBoxes + 1];
    for (int i = 0; i < nbBoxes; i++) {
        boxes[i] = new FruitBox(boxSize + 1);
        for (int j = 0; j < (int)boxSize; j++)
            boxes[i]->pushFruit(fruits[i * boxSize + j]);
    }
    boxes[nbBoxes] = nullptr;
    return boxes;
}

IFruit **FruitUtils::unpack(FruitBox **fruitBoxes)
{
    int x = 0;
    size_t count = 0;
    for (size_t i = 0; fruitBoxes[i]; i++) {
        x += fruitBoxes[i]->nbFruits();
    }
    IFruit **fruits = new IFruit *[x + 1];
    for (size_t i = 0; fruitBoxes[i]; i++) {
        size_t nb = fruitBoxes[i]->nbFruits();
        for (size_t j = 0; nb > j; count++, j++) {
            fruits[count] = fruitBoxes[i]->popFruit();
        }
    }
    fruits[x] = nullptr;
    return fruits;
}