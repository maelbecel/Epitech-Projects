/*
** EPITECH PROJECT, 2023
** Borg
** File description:
** Borg
*/

#include "Borg.hpp"

#include <iostream>

namespace Borg {
    // ========================================================================
    //                               Borg::Ship
    // ========================================================================
    Ship::Ship(int weapon, short repair)
    {
        this->_side = 300;
        this->_maxWarp = 9;
        this->_home = UNICOMPLEX;
        this->_location = _home;
        this->_shield = 100;
        this->_weaponFrequency = weapon;
        this->_repair = repair;
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
        std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
        std::cout << "Resistance is futile." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        this->_coreReactor = core;
    }

    void Ship::checkCore(void)
    {
        if (this->_coreReactor->checkReactor()->isStable())
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }

    bool Ship::move(int warp , Destination d )
    {
        if (warp <= this->_maxWarp && d != this->_location && this->_coreReactor->checkReactor()->isStable()) {
            this->_location = d;
            return true;
        }
        return false;
    }

    bool Ship::move(int warp )
    {
        if (warp <= this->_maxWarp && this->_coreReactor->checkReactor()->isStable()) {
            this->_location = this->_home;
            return true;
        }
        return false;
    }

    bool Ship::move( Destination d )
    {
        if (d != this->_location && this->_coreReactor->checkReactor()->isStable()) {
            this->_location = d;
            return true;
        }
        return false;
    }

    bool Ship::move()
    {
        if (this->_coreReactor->checkReactor()->isStable()) {
            this->_location = this->_home;
            return true;
        }
        return false;
    }
    int Ship::getShield()
    {
        return this->_shield;
    }

    void Ship::setShield(int shield)
    {
        this->_shield = shield;
    }

    int Ship::getWeaponFrequency ()
    {
        return this->_weaponFrequency;
    }

    void Ship::setWeaponFrequency (int frequency )
    {
        this->_weaponFrequency = frequency;
    }

    short Ship::getRepair ()
    {
        return this->_repair;
    }

    void Ship::setRepair ( short repair )
    {
        this->_repair = repair;
    }

    void Ship::fire (Federation::Starfleet::Ship *target)
    {
        target->setShield(target->getShield() - this->_weaponFrequency);
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::fire (Federation::Ship *target)
    {
        target->getCore()->checkReactor()->setStability(false);
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::repair ()
    {
        if (this->_repair > 0) {
            this->_shield = 100;
            std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
            this->_repair--;
        } else
            std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}
