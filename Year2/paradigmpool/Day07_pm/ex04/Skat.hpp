/*
** EPITECH PROJECT, 2023
** skat
** File description:
** skat
*/

#ifndef SKAT_CPP_
    #define SKAT_CPP_

    #include <iostream>
    #include "Phaser.hpp"
    #include "KreogCom.hpp"

    class Skat {
        public:
            Skat (const std::string &name = "bob" ,int stimPaks = 15, int serial , int x , int y, Phaser :: AmmoType type);
            ~Skat();
            int &stimPaks();
            const std::string &name();
            void shareStimPaks (int number , int &stock ) ;
            void addStimPaks( unsigned int number ) ;
            void useStimPaks() ;
            void status() ;
        private:
            std::string _name;
            int _steamPaks;
            KreogCom _kreog;
            Phaser _phaser;
    };

#endif /* !SKAT_CPP_ */
