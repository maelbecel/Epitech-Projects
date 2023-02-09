/*
** EPITECH PROJECT, 2023
** Parts
** File description:
** parts
*/

#include "Parts.hpp"
#include <iostream>

/// ===========================================================================
///                              Arms
/// ===========================================================================
Arms::Arms(std::string serial, bool functionnal)
{
    _serial = serial;
    _functionnal = functionnal;
}

bool Arms::isFunctionnal(void) const
{
    return _functionnal;
}

std::string Arms::serial(void) const
{
    return _serial;
}

void Arms::informations(void) const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

/// ===========================================================================
///                              Legs
/// ===========================================================================
Legs::Legs(std::string serial, bool functionnal)
{
    _serial = serial;
    _functionnal = functionnal;
}

bool Legs::isFunctionnal(void) const
{
    return _functionnal;
}

std::string Legs::serial(void) const
{
    return _serial;
}

void Legs::informations(void) const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}

/// ===========================================================================
///                              Head
/// ===========================================================================
Head::Head(std::string serial, bool functionnal)
{
    _serial = serial;
    _functionnal = functionnal;
}

bool Head::isFunctionnal(void) const
{
    return _functionnal;
}

std::string Head::serial(void) const
{
    return _serial;
}

void Head::informations(void) const
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}
