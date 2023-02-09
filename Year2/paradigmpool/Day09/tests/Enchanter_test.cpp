/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#include "../ICharacter.hpp"
#include "../Enchanter.hpp"
#include "../Peasant.hpp"
#include "../IPotion.hpp"
#include "../PowerPotion.hpp"
#include "../PoisonPotion.hpp"
#include "../HealthPotion.hpp"
#include <string>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Enchanter_Constructor, Enchanter_construct) {
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    Enchanter enchanter = Enchanter("Enchanter", 1000);

    std::cout.rdbuf( oldCoutStreamBuf );
    std::stringstream req;
    req << "Enchanter goes for an adventure." << std::endl << "Enchanter learns magic from his spellbook."<< std::endl;
    cr_assert_str_eq(req.str().c_str(), strCout.str().c_str());
}


Test(Enchanter_attack, Test_the_enchanter_attack) {
    Enchanter enchanter = Enchanter("Enchanter", 100);
    cr_assert_eq(enchanter.attack(), 0);
    cr_assert_eq(enchanter.getPower(), 100);
    cr_assert_eq(enchanter.getHp(), 100);
    PoisonPotion poison_potion ;
    enchanter.drink(poison_potion);
    enchanter.drink(poison_potion);
    cr_assert_eq(enchanter.attack(), 0);
}

Test(Enchanter_special, Test_the_enchanter_special) {
    Enchanter enchanter = Enchanter("Enchanter", 100);
    cr_assert_eq(enchanter.special(), 99);
    cr_assert_eq(enchanter.getPower(), 50);
    cr_assert_eq(enchanter.getHp(), 100);
    PoisonPotion poison_potion ;
    enchanter.drink(poison_potion);
    enchanter.drink(poison_potion);
    cr_assert_eq(enchanter.special(), 0);
}

Test(Enchanter_rest, Test_the_enchanter_rest) {
    Enchanter enchanter = Enchanter("Enchanter", 100);
    enchanter.rest();
    cr_assert_eq(enchanter.getPower(), 100);
    cr_assert_eq(enchanter.getHp(), 100);
    PoisonPotion poison_potion ;
    enchanter.drink(poison_potion);
    enchanter.drink(poison_potion);
    enchanter.rest();
}
