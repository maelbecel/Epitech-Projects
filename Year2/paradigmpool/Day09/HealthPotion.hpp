/*
** EPITECH PROJECT, 2023
** hela
** File description:
** heal
*/

#ifndef HEALTHPOTION_CPP_
    #define HEALTHPOTION_CPP_

    #include "IPotion.hpp"

    class HealthPotion : public IPotion {
        public:
            HealthPotion();
            ~HealthPotion();
            int getHealth() const;
            int getPower() const;
        private:
            int _health = 50;
            int _power = 0;
    };

#endif /* !HEALTHPOTION_CPP_ */
