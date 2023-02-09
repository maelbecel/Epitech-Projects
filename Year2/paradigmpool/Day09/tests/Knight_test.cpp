/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#include "../ICharacter.hpp"
#include "../Peasant.hpp"
#include "../IPotion.hpp"
#include "../Knight.hpp"
#include "../PowerPotion.hpp"
#include "../PoisonPotion.hpp"
#include "../HealthPotion.hpp"
#include <string>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Knight_attack, Test_the_knight_attack) {
    Knight knight = Knight("Knight", 100);
    cr_assert_eq(knight.attack(), 20);
    cr_assert_eq(knight.getPower(), 90);
    cr_assert_eq(knight.getHp(), 100);
    PoisonPotion poison_potion ;
    knight.drink(poison_potion);
    knight.drink(poison_potion);
    cr_assert_eq(knight.attack(), 0);
}

Test(Knight_special, Test_the_knight_special) {
    Knight knight = Knight("Knight", 100);
    cr_assert_eq(knight.special(), 50);
    cr_assert_eq(knight.getPower(), 70);
    cr_assert_eq(knight.getHp(), 100);
    PoisonPotion poison_potion ;
    knight.drink(poison_potion);
    knight.drink(poison_potion);
    cr_assert_eq(knight.special(), 0);
}

Test(Knight_rest, Test_the_knight_rest) {
    Knight knight = Knight("Knight", 100);
    knight.rest();
    cr_assert_eq(knight.getPower(), 100);
    cr_assert_eq(knight.getHp(), 100);
    PoisonPotion poison_potion ;
    knight.drink(poison_potion);
    knight.drink(poison_potion);
    knight.rest();
}


