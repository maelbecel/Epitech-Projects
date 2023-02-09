/*
** EPITECH PROJECT, 2023
** buzz
** File description:
** buzz
*/

#ifndef BUZZ_CPP_
    #define BUZZ_CPP_

    #include "Toy.hpp"

    class Buzz : public Toy {
        public:
            Buzz(const std::string name, const std::string file = "buzz.txt" );
            ~Buzz();
        protected:
        private:
    };

#endif /* !BUZZ_CPP_ */
