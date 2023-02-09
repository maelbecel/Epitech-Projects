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

class TestFruit : public AFruit {
    public:
        TestFruit(std::string name) : AFruit(name, 5, false) {
            std::cout << getName() << " lives." << std::endl;
        }
        ~TestFruit() {
            std::cout << getName() << " dies." << std::endl;
        }
};

Test(FruitFactory_test, test_the_factory)
{
    FruitFactory factory;
}

Test(RegFruitFactory_test, test_the_reg_factory)
{
    FruitFactory factory;

    factory.registerFruit(new BloodOrange);
    factory.registerFruit(new Lemon);
    factory.registerFruit(new Orange);
    factory.registerFruit(new TestFruit("orange"));
}

Test(UnRegFruitFactory_test, test_the_unreg_factory)
{
    FruitFactory factory;

    factory.unregisterFruit("orange");
    factory.registerFruit(new BloodOrange);
    factory.registerFruit(new Lemon);
    factory.registerFruit(new Orange);
    factory.unregisterFruit("orange");
    factory.unregisterFruit("orange");
    factory.unregisterFruit("blood orange");
    factory.unregisterFruit("lemon");
}

Test(createFruitFactory_test, test_the_crereg_factory)
{
    FruitFactory factory;
    factory.registerFruit(new BloodOrange);
    factory.registerFruit(new Lemon);
    factory.registerFruit(new Orange);
    factory.createFruit("orange");
    IFruit * fruit1 = factory.createFruit("orange");
    IFruit * fruit2 = factory.createFruit("jej");

}

