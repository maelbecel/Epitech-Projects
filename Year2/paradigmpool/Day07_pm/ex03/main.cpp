/*
** EPITECH PROJECT, 2023
** main
** File description:
** jej
*/

#include <iostream>
#include "Phaser.hpp"
#include "Sounds.hpp"

const std::string Sounds::Regular = "zebi";
const std::string Sounds::Rocket = "Boooooooooom";
const std::string Sounds::Plasma = "zebi";

int main ()
{
    Phaser p (5 , Phaser :: ROCKET ) ;
    p . fire () ;
    p . reload () ;
    std :: cout << "Firing all ammunition" << std :: endl ;
    while ( p . getCurrentAmmos () > 0)
    p . fire () ;
    p .addAmmo(Phaser ::PLASMA);
    p.changeType(Phaser ::PLASMA);
    p.fire();
    return 0;
}