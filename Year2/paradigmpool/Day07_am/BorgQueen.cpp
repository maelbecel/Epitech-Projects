/*
** EPITECH PROJECT, 2023
** BorgQueen
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

namespace Borg {
    // ========================================================================
    //                               Borg::BorgQueen
    // ========================================================================
    BorgQueen::BorgQueen(void) : movePtr(&Ship::move), firePtr(&Ship::fire), destroyPtr(&Ship::fire) {}

    bool BorgQueen::move ( Borg :: Ship * ship , Destination dest )
    {
        return (ship->*movePtr)(dest);
    }

    void BorgQueen::fire ( Borg :: Ship * ship , Federation :: Starfleet :: Ship * target )
    {
        (ship->*firePtr)(target);
    }

    void BorgQueen::destroy ( Borg :: Ship * ship , Federation :: Ship * target )
    {
        (ship->*destroyPtr)(target);
    }
}