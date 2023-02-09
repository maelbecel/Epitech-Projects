/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#include "../ICharacter.hpp"
#include "../Peasant.hpp"
#include "../IPotion.hpp"
#include "../PowerPotion.hpp"
#include "../PoisonPotion.hpp"
#include "../HealthPotion.hpp"
#include <string>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(getName, Test_the_name) {
        Peasant p = Peasant("Bob" , 35);
        cr_assert_eq(p.getName(), "Bob");
}

Test(getPower, Test_the_power) {
        Peasant p = Peasant("Bob" , 35);
        cr_assert_eq(p.getPower(), 35);
}

Test(getHp, Test_the_hp) {
        Peasant p = Peasant("Bob" , 35);
        cr_assert_eq(p.getHp(), 100);
}

Test(assertPower, Test_the_power_assertion) {
        Peasant p = Peasant("Bob" , 35);
        cr_assert_eq(p.assertPower(0), true);
        cr_assert_eq(p.assertPower(100), false);
        p.damage(150);
        cr_assert_eq(p.assertPower(0), false);
}

Test(attack, Test_the_attack) {
        Peasant p = Peasant("Bob" , 35);
        cr_assert_eq(p.attack(), 5);
        cr_assert_eq(p.getPower(), 25);
        PoisonPotion poison_potion ;
        p.drink(poison_potion);
        p.drink(poison_potion);
        cr_assert_eq(p.attack(), 0);
        cr_assert_eq(p.getPower(), 25);
}

Test(special, Test_the_special) {
        Peasant p = Peasant("Bob" , 35);
        cr_assert_eq(p.special(), 0);
        cr_assert_eq(p.getPower(), 35);
        PoisonPotion poison_potion ;
        p.drink(poison_potion);
        p.drink(poison_potion);
        cr_assert_eq(p.special(), 0);
        cr_assert_eq(p.getPower(), 35);
}

Test(rest, Test_the_rest) {
        Peasant p = Peasant("Bob" , 35);
        p.rest();
        cr_assert_eq(p.getPower(), 65);
        PoisonPotion poison_potion ;
        p.drink(poison_potion);
        p.drink(poison_potion);
        p.rest();
        cr_assert_eq(p.getPower(), 65);
}

Test(damage, Test_the_damage) {
        Peasant p = Peasant("Bob" , 35);
        p.damage(10);
        cr_assert_eq(p.getHp(), 90);
        p.damage(1000);
        cr_assert_eq(p.getHp(), 0);
        PoisonPotion poison_potion ;
        IPotion &potion = poison_potion;
        p.drink(potion);
        p.drink(potion);
        p.damage(10);
        cr_assert_eq(p.getHp(), 0);
        Peasant enchanter = Peasant("Enchanter", 100);
        enchanter.damage(500);
}

Test(drink, Test_the_drink) {
        Peasant p = Peasant("Bob" , 35);
        PoisonPotion poison_potion ;
        HealthPotion health_potion ;
        PowerPotion power_potion ;
        IPotion &potion = health_potion ;
        p.drink(poison_potion);
        cr_assert_eq(p.getHp(), 50);
        p.drink(health_potion);
        cr_assert_eq(p.getHp(), 100);
        p.drink(power_potion);
        cr_assert_eq(p.getPower(), 85);
        p.drink(potion);
        cr_assert_eq(p.getHp(), 100);
        p.damage(150);
        p.drink(health_potion);
        p.drink(power_potion);
        cr_assert_eq(power_potion.getHealth(), 0);
}