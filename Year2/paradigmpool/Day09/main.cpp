/*
** EPITECH PROJECT, 2023
** m
** File description:
** m
*/

#include "Peasant.hpp"

// int main ( void )
// {
// ICharacter * peasant = new Peasant ("Gildas", 42) ;
// PoisonPotion poison_potion ;
// HealthPotion health_potion ;
// IPotion &potion = health_potion ;
// std :: cout << peasant-> getName () << ": " << peasant-> getHp () << "HP , "
// << peasant->getPower () << " PP." << std :: endl ;
// peasant->drink ( poison_potion ) ;
// std :: cout << peasant->getName () << ": " << peasant->getHp () << "HP , "
// << peasant->getPower () << " PP." << std :: endl ;
// peasant->drink ( potion ) ;
// std :: cout << peasant-> getName () << ": " << peasant->getHp () << "HP , "
// << peasant->getPower () << " PP." << std :: endl ;
// delete peasant ;
// }

int main (void)
{
    Peasant enchanter = Peasant("Bob", 100);
    enchanter.damage(500);
}