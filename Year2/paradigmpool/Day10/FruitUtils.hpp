/*
** EPITECH PROJECT, 2023
** Fruitu
** File description:
** fruitU
*/

#ifndef FRUITUTILS_CPP_
    #define FRUITUTILS_CPP_

    #include "FruitBox.hpp"
    #include "ABerry.hpp"
    #include "ACitrus.hpp"
    #include "Lemon.hpp"

    class FruitUtils {
        public:
            FruitUtils();
            ~FruitUtils();
            static void sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
            static FruitBox **pack(IFruit **fruits, unsigned int boxSize);
            static IFruit **unpack(FruitBox **fruitBoxes);
        protected:
        private:
    };

#endif /* !FRUITUTILS_CPP_ */
