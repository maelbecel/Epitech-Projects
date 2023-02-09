/*
** EPITECH PROJECT, 2023
** toy
** File description:
** toy
*/

#ifndef TOYSTORY_CPP_
    #define TOYSTORY_CPP_

    #include <iostream>
    #include "Toy.hpp"

    class ToyStory {
        public:
            ToyStory();
            ~ToyStory();
            static void tellMeAStory(const std::string name, Toy &toy1, bool (Toy::*func1)(const std::string str), Toy &toy2,  bool (Toy::*func2)(const std::string str));
        protected:
        private:
    };

#endif /* !TOYSTORY_CPP_ */
