/*
** EPITECH PROJECT, 2023
** ch
** File description:
** ch
*/

#ifndef ICHARACTER_CPP_
    #define ICHARACTER_CPP_

    #include <string>
    #include "IPotion.hpp"
    #include "PoisonPotion.hpp"
    #include "PowerPotion.hpp"
    #include "HealthPotion.hpp"

    class ICharacter {
        public:
            virtual const std :: string & getName () const = 0;
            virtual int getPower () const = 0;
            virtual int getHp () const = 0;
            virtual int attack() = 0;
            virtual int special() = 0;
            virtual void rest() = 0;
            virtual void damage(int damage) = 0;
            virtual void drink(const IPotion &potion) = 0;
            virtual void drink(const HealthPotion &potion) = 0;
            virtual void drink(const PoisonPotion &potion) = 0;
            virtual void drink(const PowerPotion &potion) = 0;
            ICharacter () = default;
            virtual ~ICharacter () = default;
        protected:
        private:
    };

#endif /* !ICHARACTER_CPP_ */