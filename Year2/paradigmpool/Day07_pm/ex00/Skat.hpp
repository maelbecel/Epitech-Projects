/*
** EPITECH PROJECT, 2023
** skat
** File description:
** skat
*/

#ifndef SKAT_CPP_
    #define SKAT_CPP_

    #include <iostream>

    class Skat {
        public:
            Skat (const std::string &name = "bob" ,int stimPaks = 15);
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
    };

#endif /* !SKAT_CPP_ */
