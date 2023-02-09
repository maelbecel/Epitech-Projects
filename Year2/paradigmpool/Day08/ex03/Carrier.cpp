/*
** EPITECH PROJECT, 2023
** Carrier
** File description:
** carrier
*/

#include "Carrier.hpp"

#define MOVE_FEE(x, y, NbDroid) (abs(x) + abs(y)) * (10 + (NbDroid))

Carrier::Carrier(std::string id = "") : Id(id), Energy(300), Attack(100), Toughness(90), Speed(0)
{
    for (size_t i = 0; i < 5; i++)
        Droids[i] = nullptr;
}

Carrier::~Carrier()
{
    for (size_t i = 0; i < 5; i++)
        delete Droids[i];
}

Carrier &Carrier::operator<<(Droid *&droid)
{
    if (droid == nullptr)
        return *this;

    for (int i = 0; i < 5; i++) {
        if (Droids[i] == nullptr) {
            Droids[i] = droid;
            droid = nullptr;
            Speed = (Speed == 0) ? 90 : Speed - 10;
            return *this;
        }
    }
    return *this;
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    int i = 0;
    for (;Droids[i] == nullptr; i++);
    droid = Droids[i];
    Droids[i] = nullptr;
    return *this;
}

Droid *&Carrier::operator[](size_t i)
{
    return Droids[i];
}

void Carrier::setSpeed(size_t x)
{
    this->Speed = x;
}

size_t Carrier::getSpeed() const
{
    return this->Speed;
}

void Carrier::setEnergy(size_t x)
{
    if ((this->Energy + x) >= 600)
        this->Energy = 600;
    else
        this->Energy = x;
}

size_t Carrier::getEnergy() const
{
    return this->Energy;
}

std::string Carrier::getId(void) const
{
    return this->Id;
}

Droid *Carrier::getDroid(int i) const
{
    if (i >= 5)
        return nullptr;
    return Droids[i];
}

size_t Carrier::GetLength(void) const
{
    int x = 0;
    for (int i = 0; i < 5; i++) {
        if (Droids[i] != nullptr) {
            x++;
        }
    }
    return x;
}

Carrier &Carrier::operator~()
{
    int x = 0;
    for (int i = 0; i < 5; i++) {
        if (Droids[i] != nullptr) {
            x++;
        }
    }
    if (x == 0)
        Speed = 0;
    else
        Speed = 100 - (10 * x);
    return *this;
}

bool Carrier::operator()(int x, int y)
{
    if (this->Energy < MOVE_FEE(x, y, this->GetLength()) || Speed == 0)
        return false;
    this->Energy -= MOVE_FEE(x, y, this->GetLength());
    return true;
}

std::ostream &operator<<(std::ostream &str, const Carrier &carrier)
{
    str << "Carrier " << carrier.getId() << " Droid(s) on-board:" << std::endl;
    for (size_t i = 0; i < 5; i++) {
        str << "[" << i << "] : ";
        if (carrier.getDroid(i) == nullptr)
            str << "Free" << std::endl;
        else
            str << *carrier.getDroid(i) << std::endl;
    }
    str << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return str;
}
