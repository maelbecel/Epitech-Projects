/*
** EPITECH PROJECT, 2023
** Federation
** File description:
** Federation
*/

#include "Federation.hpp"
#include "Borg.hpp"


namespace Federation {
    // ========================================================================
    //                            Federation::Ship
    // ========================================================================
    Ship::Ship(int length, int width, std::string name)
    {
        this->_length = length ;
        this->_width = width ;
        this->_name = name ;
        this->_maxWarp = 1 ;
        this->_home = VULCAN;
        this->_location = _home;
        std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
        std::cout << "It is " << this ->_length << " m in length and " << this -> _width << " m in width." << std :: endl ;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        this->_coreReactor = core;
        std::cout << this->_name << ": The core is set." << std::endl;
    }

    void Ship::checkCore(void)
    {
        std::cout << this->_name << ": The core is " << (this->_coreReactor->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
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

    WarpSystem::Core *Ship::getCore(void)
    {
        return this->_coreReactor;
    }

    namespace Starfleet {
        // ====================================================================
        //                     Federation::Starfleet::Ship
        // ====================================================================
        Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        {
            this->_length = length ;
            this->_width = width ;
            this->_name = name ;
            this->_maxWarp = maxWarp ;
            this->_home = EARTH;
            this->_location = _home;
            this->_photonTorpedo = torpedo;
            this->_shield = 100;
            std::cout << "The ship USS " << this->_name << " has been finished." << std::endl ;
            std::cout << "It is " << this ->_length << " m in length and " << this -> _width << " m in width." << std :: endl ;
            std::cout << "It can go to Warp " << this ->_maxWarp << "!" << std::endl ;
            if (torpedo)
                std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
        }

        void Ship::setupCore(WarpSystem::Core *core)
        {
            this->_coreReactor = core;
            std::cout << "USS " << this->_name << ": The core is set." << std::endl;
        }

        void Ship::checkCore(void)
        {
            std::cout << "USS " << this->_name << ": The core is " << (this->_coreReactor->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
        }

        void Ship::promote(Captain *captain)
        {
            this->_captain = captain;
            std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
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

        int Ship::getShield ()
        {
            return this->_shield;
        }

        void Ship::setShield (int shield )
        {
            this->_shield = shield;
        }

        int Ship::getTorpedo ()
        {
            return this->_photonTorpedo;
        }

        void Ship::setTorpedo (int torpedo )
        {
            this->_photonTorpedo = torpedo;
        }

        void Ship::fire ( Borg :: Ship * target )
        {
            if (this->_photonTorpedo == 0)
                return;
            this->_photonTorpedo--;
            std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
            target->setShield(target->getShield() - 50);
            if (this->_photonTorpedo == 0)
                std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
        }
        void Ship::fire (int torpedoes , Borg :: Ship * target )
        {
            if (this->_photonTorpedo == 0)
                return;
            if (torpedoes > this->_photonTorpedo) {
                std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
                return;
            }
            this->_photonTorpedo -= torpedoes;
            std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
            target->setShield(target->getShield() - 50 * torpedoes);
            if (this->_photonTorpedo == 0)
                std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
        }

        // ====================================================================
        //                     Federation::Starfleet::Captain
        // ====================================================================
        Captain::Captain(std::string name) : _name(name), _age(0) {}

        std::string Captain::getName(void)
        {
            return this->_name;
        }

        int Captain::getAge(void)
        {
            return this->_age;
        }

        void Captain::setAge(int age)
        {
            this->_age = age;
        }

        // ====================================================================
        //                     Federation::Starfleet::Ensign
        // ====================================================================
        Ensign::Ensign(std::string name) : _name(name)
        {
            std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
        }
    }
}

