/*
** EPITECH PROJECT, 2023
** peas
** File description:
** peas
*/

#include <string>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../AFruit.hpp"
#include "../IFruit.hpp"
#include "../BloodOrange.hpp"


Test(getVitamin, try_to_get_vitamins) {
    AFruit bob = AFruit("bob", 45);
    bob.peel();
    cr_assert_eq(bob.getVitamins(), 45);

    AFruit bobito = AFruit("bobito", 0, true);
    AFruit bobitos = AFruit("bobitos", 20, false);
    cr_assert_eq(bobito.getVitamins(), 0);
    cr_assert_eq(bobitos.getVitamins(), 0);
}

Test(getName, try_to_get_name) {
    AFruit bob = AFruit("bob", 45);
    AFruit bobito = AFruit("bobito", 0, true);
    AFruit bobitos = AFruit("bobitos", 20, false);
    cr_assert_eq(bob.getName(), "bob");
    cr_assert_eq(bobito.getName(), "bobito");
    cr_assert_eq(bobitos.getName(), "bobitos");
}

Test(isPeeled, try_to_check_if_isPilled ) {
    AFruit bob = AFruit("bob", 45);
    AFruit bobito = AFruit("bobito", 0, true);
    AFruit bobitos = AFruit("bobitos", 20, false);
    cr_assert_eq(bobitos.isPeeled(), false);
    bobitos.peel();
    cr_assert_eq(bobitos.isPeeled(), true);
    cr_assert_eq(bob.isPeeled(), false);
    cr_assert_eq(bobito.isPeeled(), true);
}

Test(setVitamins, try_to_set_vitamins) {
    AFruit bob = AFruit("bob", 45);

    bob.setVitamins(0);
    cr_assert_eq(bob.getVitamins(), 0);
}


Test(setName, try_to_set_name) {
    AFruit bob = AFruit("bob", 45);

    bob.setName("bobito");
    cr_assert_eq(bob.getName(), "bobito");
}

Test(copy, try_to_copy) {
    BloodOrange borange;
    AFruit bob = AFruit(borange);
    AFruit bobito;
    AFruit Booba = AFruit((*borange.clone()));
}