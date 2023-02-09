/*
** EPITECH PROJECT, 2023
** admiral
** File description:
** admiral
*/

#include "Admiral.hpp"
#include "Federation.hpp"

namespace Federation {
    namespace Starfleet {
        // ====================================================================
        //                     Federation::Starfleet::Admiral
        // ====================================================================
        Admiral::Admiral(std::string name)
        {
            this->_name = name;
            this->movePtr = &Ship::move;
            this->firePtr = &Ship::fire;
            std::cout << "Admiral " << name << " ready for action." << std::endl;
        }

        void Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
        {
            std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
            (ship->*firePtr)(target);
        }

        bool Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
        {
            return (ship->*movePtr)(dest);
        }
    }
}