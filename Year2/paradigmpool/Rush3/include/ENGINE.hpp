/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** ENGINE
*/

#ifndef ENGINE_HPP_
    #define ENGINE_HPP_
    #include "CURSES.hpp"
    #include "SFML.hpp"
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <iostream>
    #include "../include/Cpu.hpp"
    #include "../include/Info.hpp"
    #include "../include/Memory.hpp"
    #include "../include/Network.hpp"
    #include "../include/Weather.hpp"
    #include "../include/Battery.hpp"

    #define RED 10
    #define GREEN 11
    #define YELLOW 12
    #define GREY 13
    #define WHITE 14


class ENGINE {
    private:
        bool _switch{false}; // true: SFML | false: curses
        bool exiting{false}; // true: exit | false: continue
        SFML _sfml;
        Curses _curses;
    
    public:
        ENGINE();
        ~ENGINE();

        /* ACCESSEUR */
        bool getSwitch();
        void setSwitch(bool);

        bool getExit();
        void setExit(bool);

        /* METHOD */
        void loop();
};

extern bool EXIT;

#endif /* !ENGINE_HPP_ */
