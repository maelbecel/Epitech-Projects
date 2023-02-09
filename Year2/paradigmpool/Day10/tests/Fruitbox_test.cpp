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
#include "../FruitBox.hpp"

Test(getSize, test_getsize)
{
    FruitBox bob = FruitBox(4);
    FruitBox bobito = FruitBox(0);
    FruitBox bobitos = FruitBox(20);
    cr_assert_eq(bobitos.getSize(), 20);
    cr_assert_eq(bobito.getSize(), 0);
    cr_assert_eq(bob.getSize(), 4);
}

Test(nbFruits, test_nbFruits)
{
    FruitBox bob = FruitBox(4);
    FruitBox bobito = FruitBox(0);
    FruitBox bobitos = FruitBox(20);
    cr_assert_eq(bobitos.nbFruits(), 0);
    cr_assert_eq(bobito.nbFruits(), 0);
    cr_assert_eq(bob.nbFruits(), 0);
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    cr_assert_eq(bob.nbFruits(), 4);
    bobito.pushFruit(new BloodOrange());
    cr_assert_eq(bobito.nbFruits(), 0);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.nbFruits(), 1);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.nbFruits(), 2);
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.nbFruits(), 6);
}

Test(popFruits, test_popFruits)
{
    FruitBox bob = FruitBox(4);
    FruitBox bobito = FruitBox(0);
    FruitBox bobitos = FruitBox(20);
    cr_assert_eq(bobitos.popFruit(), nullptr);
    cr_assert_eq(bobito.popFruit(), nullptr);
    cr_assert_eq(bob.popFruit(), nullptr);
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    cr_assert_eq(bob.nbFruits(), 4);
    bobito.pushFruit(new BloodOrange());
    cr_assert_eq(bobito.nbFruits(), 0);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.nbFruits(), 1);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.nbFruits(), 2);
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.nbFruits(), 6);
    bobitos.popFruit();
    cr_assert_eq(bobitos.nbFruits(), 5);
    bobitos.popFruit();
    bobitos.popFruit();
    bobitos.popFruit();
    bobitos.popFruit();
    cr_assert_eq(bobitos.nbFruits(), 1);
    bobitos.popFruit();
    cr_assert_eq(bobitos.nbFruits(), 0);
    cr_assert_eq(bobitos.popFruit(), nullptr);
}

Test(getQueue, test_getQueue)
{
    FruitBox bob = FruitBox(4);
    FruitBox bobito = FruitBox(0);
    FruitBox bobitos = FruitBox(20);
    cr_assert_eq(bobitos.getQueue().size(), 0);
    cr_assert_eq(bobito.getQueue().size(), 0);
    cr_assert_eq(bob.getQueue().size(), 0);
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    cr_assert_eq(bob.getQueue().size(), 4);
    bobito.pushFruit(new BloodOrange());
    cr_assert_eq(bobito.getQueue().size(), 0);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.getQueue().size(), 1);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.getQueue().size(), 2);
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.getQueue().size(), 6);
    bobitos.popFruit();
    cr_assert_eq(bobitos.getQueue().size(), 5);
    bobitos.popFruit();
    bobitos.popFruit();
    bobitos.popFruit();
    bobitos.popFruit();
    cr_assert_eq(bobitos.getQueue().size(), 1);
    bobitos.popFruit();
    cr_assert_eq(bobitos.getQueue().size(), 0);
    cr_assert_eq(bobitos.getQueue().size(), 0);
}

Test(setQueue, test_setQueue)
{
    FruitBox bob = FruitBox(4);
    FruitBox bobito = FruitBox(0);
    FruitBox bobitos = FruitBox(20);
    std::deque<IFruit *> queue;
    bob.setQueue(queue);
    bobito.setQueue(queue);
    bobitos.setQueue(queue);
    cr_assert_eq(bobitos.getQueue().size(), 0);
    cr_assert_eq(bobito.getQueue().size(), 0);
    cr_assert_eq(bob.getQueue().size(), 0);
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    cr_assert_eq(bob.getQueue().size(), 4);
    bobito.pushFruit(new BloodOrange());
    cr_assert_eq(bobito.getQueue().size(), 0);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.getQueue().size(), 1);
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.getQueue().size(), 2);
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    bobitos.pushFruit(new BloodOrange());
    cr_assert_eq(bobitos.getQueue().size(), 6);
    bobitos.popFruit();
    cr_assert_eq(bobitos.getQueue().size(), 5);
    bobitos.popFruit();
    bobitos.popFruit();
    bobitos.popFruit();
    bobitos.popFruit();
    cr_assert_eq(bobitos.getQueue().size(), 1);
    bobitos.popFruit();
    cr_assert_eq(bobitos.getQueue().size(), 0);
    cr_assert_eq(bobitos.getQueue().size(), 0);
}

Test(operator, test_operator)
{
    FruitBox bob = FruitBox(4);
    std::cout << bob << std::endl;
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    std::cout << bob << std::endl;
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    bob.pushFruit(new BloodOrange());
    std::cout << bob << std::endl;
}