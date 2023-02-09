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
#include "../FruitUtils.hpp"

class TestFruit : public AFruit {
    public:
        TestFruit(std::string name) : AFruit(name, 5, false) {
            std::cout << getName() << " lives." << std::endl;
        }
        ~TestFruit() {
            std::cout << getName() << " dies." << std::endl;
        }
};

Test(Fruits_sort, Fruits_sort)
{
     FruitBox box (50) ;
    const FruitBox& bbox = box;
    FruitBox lemons (1) ;
    const FruitBox& blemons = lemons;
    FruitBox citrus (4) ;
    const FruitBox& bcitrus = citrus;
    FruitBox berry (2) ;
    const FruitBox& bberry = berry;
    FruitUtils utils;

    box.pushFruit(new Lemon);
    box.pushFruit(new Lemon);
    box.pushFruit(new Coconut);
    box.pushFruit(new TestFruit("Bob l'eponge"));
    box.pushFruit(new Raspberry);
    box.pushFruit(new Strawberry);
    box.pushFruit(new TestFruit("Bob l'eponge"));
    box.pushFruit(new Orange);
    box.pushFruit(new BloodOrange);
    box.pushFruit(new TestFruit("Bob l'eponge"));
    utils.sort(box, lemons, citrus, berry);
    std::cout << box << std::endl;
    cr_assert_eq(lemons.nbFruits(), 1);
    cr_assert_eq(citrus.nbFruits(), 2);
    cr_assert_eq(berry.nbFruits(), 2);
    cr_assert_eq(box.nbFruits(), 5);
}

Test(pack, utils_pack)
{
    FruitBox **boxes;
    IFruit **fruits;
    FruitUtils utils;
    fruits = new IFruit*[10];
    fruits[0] = new Lemon;
    fruits[1] = new Coconut;
    fruits[2] = new Raspberry;
    fruits[3] = new Strawberry;
    fruits[4] = new Orange;
    fruits[5] = new Strawberry;
    fruits[6] = nullptr;

    boxes = new FruitBox*[10];
    for ( int i = 0 ; i < 9 ; i++ )
    {
        boxes[i] = new FruitBox(10);
        boxes[i]->pushFruit(new Lemon);
        boxes[i]->pushFruit(new Coconut);
        boxes[i]->pushFruit(new Raspberry);
        boxes[i]->pushFruit(new Orange);
    }
    boxes[9] = nullptr;

    utils.pack(fruits, 2);
    utils.unpack(utils.pack(fruits, 2));
}