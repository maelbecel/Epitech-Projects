/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** ENGINE
*/

#include "../include/ENGINE.hpp"

/**
 * The ENGINE constructor initializes the engine.
 */
ENGINE::ENGINE() {}

/**
 * The destructor for the ENGINE class.
 */
ENGINE::~ENGINE() {}

/**
 * This function returns the value of the private variable _switch.
 *
 * @return The value of the private variable _switch.
 */
bool ENGINE::getSwitch() { return this->_switch; }

/**
 * This function sets the switch mode of the engine.
 *
 * @param switchMode true if the engine is on, false if the engine is off.
 */
void ENGINE::setSwitch(bool switchMode) {
    this->_switch = switchMode;
}

bool EXIT = false;

/**
 * It loops between the SFML and Curses game loops, depending on the value of the
 * switch
 */
void ENGINE::loop() {
    while (!EXIT) {
        if (this->getSwitch()) {
            this->_sfml.game_loop();
            this->setSwitch(false);
        } else {
            this->_curses.game_loop();
            this->setSwitch(true);
        }
    }
}
