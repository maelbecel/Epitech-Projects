/*
** EPITECH PROJECT, 2023
** droiddroid
** File description:
** droro
*/

#include "Droid.hpp"
#include <string.h>

#define ENERGY(req, max) (req > max) ? max : req

Droid::Droid(std::string serial): Id(serial), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::~Droid()
{
    delete Status;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

Droid::Droid(const Droid &damaged): Id(damaged.Id), Energy(damaged.Energy), Attack(damaged.Attack), Toughness(damaged.Attack), Status(new std::string(*damaged.Status))
{
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid &Droid::operator=(const Droid &old)
{
    Id = old.Id;
    return *this;
}

bool Droid::operator==(const Droid &other) const
{
    return (Id == other.Id && Energy == other.Energy && *Status == *other.Status);
}

bool Droid::operator!=(const Droid &other) const
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &str, const Droid &drd)
{
    str << "Droid '" << drd.getId() << "', " << *drd.getStatus() << ", " << drd.getEnergy();
    return str;
}

Droid &Droid::operator<<(size_t &energy)
{
    size_t diff = ENERGY(100 - Energy, energy);
    Energy += diff;
    energy -= diff;
    return *this;
}

void Droid::setId(std::string serial)
{
    Id = serial;
}

std::string Droid::getId() const
{
    return Id;
}

size_t Droid::getEnergy() const
{
    return Energy;
}

void Droid::setEnergy(size_t energy)
{
    Energy = (energy > 100) ? 100 : energy;
}

size_t Droid::getAttack(void) const
{
    return Attack;
}

size_t Droid::getToughness(void) const
{
    return Toughness;
}

void Droid::setStatus(std::string *status)
{
    delete Status;
    Status = status;
}

std::string *Droid::getStatus(void) const
{
    return Status;
}
