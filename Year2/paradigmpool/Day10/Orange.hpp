/*
** EPITECH PROJECT, 2023
** orange
** File description:
** orange
*/

#ifndef ORANGE_CPP_
    #define ORANGE_CPP_

    #include "ACitrus.hpp"

    class Orange : public ACitrus {
        public:
            Orange();
            Orange(std::string name, unsigned int vitamine);
            ~Orange();
        protected:
        private:
    };

#endif /* !ORANGE_CPP_ */
