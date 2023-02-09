/*
** EPITECH PROJECT, 2023
** f
** File description:
** f
*/

#include "FruitMixer.hpp"

FruitMixer::FruitMixer()
{
}

FruitMixer::~FruitMixer()
{
}

unsigned int FruitMixer::mixFruits(FruitBox& box) const
{
    unsigned int count = 0;
    std::deque <IFruit*> queue = box.getQueue();
    if (!_blade) {
        std::cout << "mixer has no blade" << std::endl;
        return 0;
    }
    for (int i = 0; (size_t)i < queue.size(); i++) {
        if (!queue[i])
            break;
        if (queue[i]->isPeeled()) {
            count += (*_blade)(*queue[i]);
            queue.erase(queue.begin() + i);
        }
    }
    box.setQueue(queue);
    return count;
}

void FruitMixer::setBlade(IFruitMixer::IBlade *blade)
{
    _blade = blade;
}