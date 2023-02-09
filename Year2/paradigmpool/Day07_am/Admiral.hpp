/*
** EPITECH PROJECT, 2023
** admiral
** File description:
** admiral
*/

#ifndef ADMIRAL_CPP_
    #define ADMIRAL_CPP_

    #include <iostream>
    #include "Destination.hpp"
    #include "Federation.hpp"

    namespace Federation {
        namespace Starfleet {
            class Admiral {
                public:
                    Admiral(std::string name);
                    bool (Ship::*movePtr)(Destination d);
                    void (Ship::*firePtr)(Borg::Ship *target);
                    void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target) ;
                    bool move(Federation::Starfleet::Ship *ship, Destination dest) ;
                protected:
                private:
                    std::string _name ;
            };
        }
    }

#endif /* !ADMIRAL_CPP_ */
