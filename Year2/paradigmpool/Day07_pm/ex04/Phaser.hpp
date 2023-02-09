/*
** EPITECH PROJECT, 2023
** Phaser
** File description:
** phaser
*/

#ifndef PHASER_CPP_
    #define PHASER_CPP_

    #include "Sounds.hpp"
    #include <iostream>

    class Phaser
    {
        public :
            enum AmmoType {
                REGULAR ,
                PLASMA ,
                ROCKET
            };
            Phaser (int maxAmmo = 20 , AmmoType type = REGULAR) ;
            ~ Phaser () ;
            void fire () ;
            void ejectClip () ;
            void changeType ( AmmoType newType ) ;
        void reload () ;
        void addAmmo ( AmmoType type ) ;
        int getCurrentAmmos () ;
    private :
        static const int Empty ;
        int _maxAmmo;
        int _currentAmmo;
        AmmoType _type;
        Sounds _sounds;
        int magazine[3];
};

#endif /* !PHASER_CPP_ */
