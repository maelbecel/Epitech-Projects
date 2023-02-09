/*
** EPITECH PROJECT, 2023
** power
** File description:
** power
*/

#ifndef POWERPOTION_CPP_
    #define POWERPOTION_CPP_

    #include "IPotion.hpp"

    class PowerPotion : public IPotion {
        public:
            int getHealth() const;
            int getPower() const;
        private:
            int _health = 0;
            int _power = 50;
    };

#endif /* !POWERPOTION_CPP_ */
