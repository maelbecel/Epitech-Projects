/*
** EPITECH PROJECT, 2023
** TOY_CPP_
** File description:
** d
*/

#ifndef TOY_CPP_
    #define TOY_CPP_

    #include "Picture.hpp"
    #include <iostream>

    class Toy {
        public:
            enum ToyType {
                BASIC_TOY,
                ALIEN,
                BUZZ,
                WOODY
            };
            Toy();
            Toy(Toy const &toy);
            ~Toy();
            Toy(ToyType type, const std::string name, const std::string filename);
            ToyType getType() const;
            std::string getName() const;
            void setName(std::string name);
            bool setAscii(std::string file);
            std::string getAscii() const;
            Toy &operator=(Toy const &toy);
        protected:
        private:
            ToyType _type;
            std::string _name;
            Picture _ascii;
    };

#endif /* !TOY_CPP_ */
