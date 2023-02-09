/*
** EPITECH PROJECT, 2023
** frout
** File description:
** frout
*/

#ifndef FRUITBOX_CPP_
    #define FRUITBOX_CPP_

    #include "IFruit.hpp"
    #include <deque>

    class FruitBox {
        public:
            FruitBox(unsigned int size);
            ~FruitBox();
            unsigned int getSize() const;
            unsigned int nbFruits() const;
            bool pushFruit(IFruit *);
            IFruit *popFruit();
            std::deque <IFruit *>getQueue() const;
            void setQueue(std::deque <IFruit *>fruits);
        protected:
        private:
            unsigned int _size;
            unsigned int _nbFruits;
            std::deque <IFruit *> _fruits;
    };

    std::ostream &operator<<(std::ostream &s, const FruitBox &fruitbox);

#endif /* !FRUITBOX_CPP_ */
