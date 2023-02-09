/*
** EPITECH PROJECT, 2023
** Poison
** File description:
** poison
*/

#ifndef POISONPOTION_CPP_
    #define POISONPOTION_CPP_

    #include "IPotion.hpp"

    class PoisonPotion : public IPotion{
        public:
            int getHealth() const;
            int getPower() const;
        private:
            int _health = -50;
            int _power = 0;
    };

#endif /* !POISONPOTION_CPP_ */
