/*
** EPITECH PROJECT, 2023
** f
** File description:
** f
*/

#ifndef FRUITMIXER_CPP_
#define FRUITMIXER_CPP_

#include "IFruitMixer.hpp"

class FruitMixer : virtual public IFruitMixer {
    public:
        FruitMixer();
        ~FruitMixer();
        unsigned int mixFruits(FruitBox& box) const override;
        void setBlade(IBlade *blade) override;
    protected:
    private:
        IBlade *_blade = nullptr;
};

#endif /* !FRUITMIXER_CPP_ */
