/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** tests
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Battery.hpp"
#include "Info.hpp"

Test(Info, test1)
{
    Info i;
    cr_assert_neq(Info::getOsName(), "");
    cr_assert_neq(Info::getHostname(), "");
    cr_assert_neq(Info::getKernelVersion(), "");
    cr_assert_neq(Info::getUserName(), "");
    cr_assert_neq(Info::getDateTime(), "");
}

Test(Battery, tst)
{
    Battery b;
    Battery::getPercent();
}
