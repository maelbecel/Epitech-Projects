/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** tests
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Weather.hpp"


Test(Weather, test1)
{
    Weather w;
}

Test(Weather, test2)
{
    Weather w;
    w.Update();
}

Test(Weather, test3)
{
    Weather w;
    w.Update();
    w.getData();
}
