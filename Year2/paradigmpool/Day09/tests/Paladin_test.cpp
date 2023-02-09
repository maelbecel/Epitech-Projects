/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#include "../ICharacter.hpp"
#include "../Peasant.hpp"
#include "../IPotion.hpp"
#include "../Paladin.hpp"
#include "../Knight.hpp"
#include "../PowerPotion.hpp"
#include "../PoisonPotion.hpp"
#include "../HealthPotion.hpp"
#include <string>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Paladin_attack, Test_the_paladin_attack) {
    Paladin paladin = Paladin("Paladin", 100);
    cr_assert_eq(paladin.attack(), 20);
    cr_assert_eq(paladin.getPower(), 90);
    cr_assert_eq(paladin.getHp(), 100);
    PoisonPotion poison_potion ;
    paladin.drink(poison_potion);
    paladin.drink(poison_potion);
    cr_assert_eq(paladin.attack(), 0);
}

Test(Paladin_special, Test_the_paladin_special) {
    Paladin paladin = Paladin("Paladin", 100);
    cr_assert_eq(paladin.special(), 99);
    cr_assert_eq(paladin.getPower(), 50);
    cr_assert_eq(paladin.getHp(), 100);
    PoisonPotion poison_potion ;
    paladin.drink(poison_potion);
    paladin.drink(poison_potion);
    cr_assert_eq(paladin.special(), 0);
}

Test(Paladin_rest, Test_the_paladin_rest) {
    Paladin paladin = Paladin("Paladin", 100);
    paladin.rest();
    cr_assert_eq(paladin.getPower(), 100);
    cr_assert_eq(paladin.getHp(), 100);
    PoisonPotion poison_potion ;
    paladin.drink(poison_potion);
    paladin.drink(poison_potion);
    paladin.rest();
}