/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#ifndef PEASANT_CPP_
    #define PEASANT_CPP_

    #include <string>
    #include <iostream>
    #include "ICharacter.hpp"

    class Peasant : virtual public ICharacter {
        public:
            Peasant ( const std :: string & name , int power ) ;
            const std :: string & getName () const ;
            int getPower () const ;
            int getHp () const ;
            bool assertPower(int power);
            virtual int attack();
            virtual int special();
            virtual void rest();
            virtual void drink(const IPotion &potion);
            virtual void drink(const HealthPotion &potion);
            virtual void drink(const PoisonPotion &potion);
            virtual void drink(const PowerPotion &potion);
            void damage(int damage);
            ~Peasant();

        protected:
            std::string _name;
            int _power;
            int _hp;
        private:
    };

#endif /* !PEASANT_CPP_ */
