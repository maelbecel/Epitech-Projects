/*
** EPITECH PROJECT, 2023
** droiddroid
** File description:
** droro
*/

#include "Droid.hpp"
#include "DroidMemory.hpp"
#include <string.h>

#define ENERGY(req, max) (req > max) ? max : req

Droid::Droid(std::string serial): Id(serial), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
    this->BattleData = new DroidMemory();
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &damaged): Id(damaged.Id), Energy(50), Attack(25), Toughness(15), Status(new std::string(*damaged.Status))
{
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (Status)
        delete Status;
    if (BattleData)
        delete BattleData;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(const Droid &old)
{
    Id = old.Id;
    if (Status)
        delete Status;
    Status = old.Status;
    if (BattleData)
        delete BattleData;
    BattleData = old.BattleData;
    return *this;
}

bool Droid::operator==(const Droid &other) const
{
    return (*Status == *other.Status);
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

Droid &Droid::operator<<(size_t energy)
{
    Energy += ENERGY(100 - Energy, energy);
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
    Energy = energy;
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

bool Droid::operator()(const std::string *task, size_t required)
{
    if (this->Energy <= 10) {
        if (this->Energy == 10)
            this->Energy -= 10;
        if (Status)
            delete Status;
        this->Status = new std::string("Battery Low");
        delete task;
        return false;
    }
    this->Energy -= 10;
    if (this->BattleData->getExp() >= required) {
        this->BattleData->setExp(this->BattleData->getExp() + required / 2);
        if (Status)
            delete Status;
        this->Status = new std::string(*task + " - Completed!");
        delete task;
        return true;
    } else {
        this->BattleData->setExp(this->BattleData->getExp() + required);
        if (Status)
            delete Status;
        this->Status = new std::string(*task + " - Failed!");
        delete task;
        return false;
    }
}
