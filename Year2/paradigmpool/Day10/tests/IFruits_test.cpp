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
#include "../FruitMixer.hpp"
#include "../FruitFactory.hpp"

Test(Ifruits_, init_ifruts)
{
    std::cout << Orange() << std::endl;
}