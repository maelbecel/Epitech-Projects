/*
** EPITECH PROJECT, 2023
** k
** File description:
** k
*/

#ifndef ENCHANTER_CPP_
    #define ENCHANTER_CPP_

    #include "Peasant.hpp"

    class Enchanter : virtual public Peasant {
        public:
            Enchanter(const std :: string & name , int power);
            int attack();
            virtual int special();
            void rest();
            virtual ~Enchanter();

        protected:
        private:
    };

#endif /* !ENCHANTER_CPP_ */
