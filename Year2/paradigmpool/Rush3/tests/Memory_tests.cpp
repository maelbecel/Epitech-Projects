/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** tests
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Memory.hpp"
#include "Network.hpp"

Test(InfoMemory_constructor, infomem_construct)
{
    InfoMemory infoMemory("MemTotal");
    Network net;
    net.Update();
    cr_assert_neq(infoMemory.GetValue(), 0);
}

Test(Ram_get, ram_get)
{
    RAM ram;
    ram.GetMemTotal();
    ram.GetMemCurrent();
    ram.GetSwapTotal();
    ram.GetSwapCurrent();
    ram.getData();
}