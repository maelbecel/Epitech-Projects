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
#include "../ABerry.hpp"
#include "../ANut.hpp"
#include "../Almond.hpp"
#include "../Coconut.hpp"
#include "../Grapefruit.hpp"
#include "../Lemon.hpp"
#include "../Orange.hpp"
#include "../Raspberry.hpp"
#include "../Strawberry.hpp"

Test(Fruit_init, test_fruit_init)
{
    ABerry bob = ABerry("berry", 3);
    cr_assert_eq(bob.getName(), "berry");
    cr_assert_eq(bob.getVitamins(), 3);
    Almond bobito = Almond();
    cr_assert_eq(bobito.getName(), "almond");
    cr_assert_eq(bobito.getVitamins(), 0);
    Coconut bobitotonut = Coconut();
    cr_assert_eq(bobitotonut.getName(), "coconut");
    cr_assert_eq(bobitotonut.getVitamins(), 0);
    Grapefruit bobitotonutonut = Grapefruit();
    cr_assert_eq(bobitotonutonut.getName(), "grapefruit");
    cr_assert_eq(bobitotonutonut.getVitamins(), 0);
    Lemon bobitotonutonutonut = Lemon();
    cr_assert_eq(bobitotonutonutonut.getName(), "lemon");
    cr_assert_eq(bobitotonutonutonut.getVitamins(), 0);
    Orange bobitotonutonutonutonut = Orange();
    cr_assert_eq(bobitotonutonutonutonut.getName(), "orange");
    cr_assert_eq(bobitotonutonutonutonut.getVitamins(), 0);
    Raspberry bobitotonutonutonutonutonut = Raspberry();
    cr_assert_eq(bobitotonutonutonutonutonut.getName(), "raspberry");
    cr_assert_eq(bobitotonutonutonutonutonut.getVitamins(), 5);
    Strawberry bobitotonutonutonutonutonutonut = Strawberry();
    cr_assert_eq(bobitotonutonutonutonutonutonut.getName(), "strawberry");
    cr_assert_eq(bobitotonutonutonutonutonutonut.getVitamins(), 6);
}