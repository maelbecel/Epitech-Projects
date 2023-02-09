/*
** EPITECH PROJECT, 2023
** Woody
** File description:
** Woody
*/

#ifndef WOODY_CPP_
    #define WOODY_CPP_

    #include "Toy.hpp"

    class Woody : public Toy {
        public:
            Woody(const std::string name, const std::string file = "woody.txt");
            ~Woody();
            bool speak(const std ::string text) override;
        protected:
        private:
    };

#endif /* !WOODY_CPP_ */
