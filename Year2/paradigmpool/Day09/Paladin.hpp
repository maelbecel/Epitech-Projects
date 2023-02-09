/*
** EPITECH PROJECT, 2023
** pa
** File description:
** pa
*/

#ifndef PALADIN_CPP_
    #define PALADIN_CPP_
    #include "Knight.hpp"
    #include "Priest.hpp"

    class Paladin : public Knight, public Priest {
        public:
            Paladin(const std :: string & name , int power);
            int attack();
            int special();
            void rest();
            ~Paladin();
        protected:
        private:
    };

#endif /* !PALADIN_CPP_ */
