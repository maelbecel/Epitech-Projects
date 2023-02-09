/*
** EPITECH PROJECT, 2023
** Borg
** File description:
** Borg
*/

#ifndef BORG_CPP_
    #define BORG_CPP_

    #include "WarpSystem.hpp"
    #include "Destination.hpp"
    #include "Federation.hpp"

    namespace Borg {
        class Ship {
            public:
                Ship(int weapon = 20, short repair = 3);
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                bool move(int warp , Destination d ) ;
                bool move(int warp ) ;
                bool move( Destination d ) ;
                bool move() ;
                int getShield();
                void setShield(int shield);
                int getWeaponFrequency () ;
                void setWeaponFrequency (int frequency ) ;
                short getRepair () ;
                void setRepair ( short repair ) ;
                void fire (Federation::Starfleet::Ship *target) ;
                void fire (Federation::Ship *target) ;
                void repair () ;
            protected:
            private:
                int _side;
                short _maxWarp;
                WarpSystem::Core *_coreReactor;
                Destination _location ;
                Destination _home ;
                int _shield ;
                int _weaponFrequency ;
                short _repair ;
        };
    }

#endif /* !BORG_CPP_ */
