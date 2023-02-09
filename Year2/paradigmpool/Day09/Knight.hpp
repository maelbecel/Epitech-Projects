/*
** EPITECH PROJECT, 2023
** knight
** File description:
** KNIGHT_CPP_
*/

#ifndef KNIGHT_CPP_
    #define KNIGHT_CPP_

    #include "Peasant.hpp"

    class Knight : virtual public Peasant {
        public:
            Knight( const std :: string & name , int power );
            virtual int attack();
            int special();
            void rest();
            ~Knight();
        protected:
        private:
    };

#endif /* !KNIGHT_CPP_ */
