/*
** EPITECH PROJECT, 2023
** droid droid
** File description:
** droid
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Fingerprint(random()), Exp(0) {}

DroidMemory::~DroidMemory() {}

size_t DroidMemory::getFingerprint() const
{
    return Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return Exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    Fingerprint = fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    Exp = exp;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &other)
{
    this->Exp += other.Exp;
    this->Fingerprint ^= other.Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other)
{
    other.Exp += this->Exp;
    other.Fingerprint ^= this->Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->Exp += exp;
    return *this;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &other)
{
    this->Exp += other.Exp;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const
{
    DroidMemory temp = DroidMemory();
    temp.setExp(this->Exp + other.Exp);
    temp.setFingerprint(this->Fingerprint);
    return temp;
}

DroidMemory DroidMemory::operator+(size_t exp) const
{
    DroidMemory *temp = new DroidMemory();
    temp->setExp(this->Exp + exp);
    temp->setFingerprint(this->Fingerprint);
    return *temp;
}

bool DroidMemory::operator==(const DroidMemory &other) const
{
    return this->Exp == other.Exp && this->Fingerprint == other.Fingerprint;
}

bool DroidMemory::operator!=(const DroidMemory &other) const
{
    return!(*this == other);
}

bool DroidMemory::operator<(const DroidMemory &other) const
{
    return this->Exp < other.Exp;
}

bool DroidMemory::operator>(const DroidMemory &other) const
{
    return this->Exp > other.Exp;
}

bool DroidMemory::operator<=(const DroidMemory &other) const
{
    return!(*this > other);
}

bool DroidMemory::operator>=(const DroidMemory &other) const
{
    return!(*this < other);
}

bool DroidMemory::operator==(size_t x) const
{
    return this->Exp == x;
}

bool DroidMemory::operator!=(size_t x) const
{
    return!(*this == x);
}

bool DroidMemory::operator<(size_t x) const
{
    return this->Exp < x;
}

bool DroidMemory::operator>(size_t x) const
{
    return this->Exp > x;
}

bool DroidMemory::operator<=(size_t x) const
{
    return!(*this > x);
}

bool DroidMemory::operator>=(size_t x) const
{
    return!(*this < x);
}

std::ostream &operator<<(std::ostream &str, const DroidMemory &drd)
{
    str << "DroidMemory '" << drd.getFingerprint() << "', " << drd.getExp();
    return str;
}