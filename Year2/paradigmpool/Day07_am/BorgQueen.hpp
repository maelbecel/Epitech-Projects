/*
** EPITECH PROJECT, 2023
** BorgQueen
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_CPP_
    #define BORGQUEEN_CPP_

    #include "Destination.hpp"
    #include "Borg.hpp"

    namespace Borg {
        class BorgQueen {
            public:
                BorgQueen();
                bool move ( Borg :: Ship * ship , Destination dest ) ;
                void fire ( Borg :: Ship * ship , Federation :: Starfleet :: Ship * target ) ;
                void destroy ( Borg :: Ship * ship , Federation :: Ship * target ) ;
                bool (Ship::*movePtr)(Destination d);
                void (Ship::*firePtr)(Federation::Starfleet::Ship *target);
                void (Ship::*destroyPtr)(Federation::Ship *target);
            protected:
            private:
        };
    }

#endif /* !BORGQUEEN_CPP_ */
