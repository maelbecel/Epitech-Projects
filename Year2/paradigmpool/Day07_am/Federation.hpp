/*
** EPITECH PROJECT, 2023
** Federation
** File description:
** federation
*/

#ifndef FEDERATION_CPP_
    #define FEDERATION_CPP_

    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include "WarpSystem.hpp"
    #include "Destination.hpp"

    namespace Borg {
        class Ship;
    }

    namespace Federation {
        class Ship {
            public:
                Ship(int length, int width, std::string name);
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                bool move(int warp , Destination d ) ;
                bool move(int warp ) ;
                bool move( Destination d ) ;
                bool move() ;
                WarpSystem::Core *getCore(void);
            protected:
            private:
                WarpSystem::Core *_coreReactor;
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                Destination _location ;
                Destination _home ;
        };
        namespace Starfleet {
            class Captain {
                public:
                    Captain(std::string name);
                    std::string getName(void);
                    int getAge(void);
                    void setAge(int age);
                protected:
                private:
                    std::string _name;
                    int _age;
            };

            class Ship {
                public:
                    Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 0);
                    void setupCore(WarpSystem::Core *core);
                    void checkCore(void);
                    void promote (Captain *captain);
                    bool move(int warp , Destination d ) ;
                    bool move(int warp ) ;
                    bool move( Destination d ) ;
                    bool move() ;
                    int getShield () ;
                    void setShield (int shield ) ;
                    int getTorpedo () ;
                    void setTorpedo (int torpedo ) ;
                    void fire ( Borg::Ship *target ) ;
                    void fire (int torpedoes , Borg::Ship *target ) ;
                protected:
                private:
                    WarpSystem::Core *_coreReactor;
                    int _length;
                    int _width;
                    std::string _name;
                    short _maxWarp;
                    Captain *_captain;
                    Destination _location ;
                    Destination _home ;
                    int _shield ;
                    int _photonTorpedo ;
            };

            class Ensign {
                public:
                    Ensign(std::string name);
                protected:
                private:
                    std::string _name;
            };
        }
    }

#endif /* !FEDERATION */
