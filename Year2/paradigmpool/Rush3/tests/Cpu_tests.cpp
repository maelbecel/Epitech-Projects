/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** tests
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Cpu.hpp"

Test(UpdateUsage, Try_to_update_usage_of_cpu)
{
    CPU *cpu = new CPU();
    cpu->UpdateUsage();
    delete cpu;
}

Test(GetUsage, Try_to_get_usage_of_cpu)
{
    CPU *cpu = new CPU();
    cpu->GetUsage();
    cpu->UpdateUsage();
    delete cpu;
}

Test(Destructor, Try_to_destruct_cpu)
{
    CPU cpu;
}

Test(Update, Try_to_update_cpu)
{
    CPU cpu;
    cpu.Update();
}

Test(GetData, Try_to_get_data)
{
    CPU cpu;
    cpu.getData();
}
