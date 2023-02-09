/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** main
*/

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Weather.hpp"
#include "../include/Info.hpp"
#include "../include/Memory.hpp"
#include "../include/Cpu.hpp"
#include "../include/IMonitorDisplay.hpp"
#include "../include/ENGINE.hpp"
#include "../include/Network.hpp"
#include <string.h>

int main (int ac, char **av)
{
    RAM Ram;
    CPU Cpu;
    Info Info;
    Network Net;
    Weather Weather;

    ENGINE engine;
    if (ac > 1)
        engine.setSwitch((strcmp(av[1], "sfml")) ? false : true);
    engine.loop();
    return 0;
}
