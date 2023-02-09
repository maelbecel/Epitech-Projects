/*
** EPITECH PROJECT, 2023
** f
** File description:
** f
*/

#ifndef FRUITFACTORY_CPP_
    #define FRUITFACTORY_CPP_

    #include <vector>
    #include <iostream>
    #include "IFruit.hpp"

    class FruitFactory {
        public:
            FruitFactory();
            ~FruitFactory();
            void registerFruit ( IFruit * fruit ) ;
            void unregisterFruit ( const std :: string & name ) ;
            IFruit * createFruit ( const std :: string & name ) const ;
        protected:
        private:
            std::vector <IFruit *> _reg;
    };

#endif /* !FRUITFACTORY_CPP_ */
