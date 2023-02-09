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

bool Arms::isFunctionnal(void)
{
    return _functionnal;
}

std::string Arms::serial(void)
{
    return _serial;
}

void Arms::informations(void)
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

bool Legs::isFunctionnal(void)
{
    return _functionnal;
}

std::string Legs::serial(void)
{
    return _serial;
}

void Legs::informations(void)
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

bool Head::isFunctionnal(void)
{
    return _functionnal;
}

std::string Head::serial(void)
{
    return _serial;
}

void Head::informations(void)
{
    std::cout << "\t[Parts] Head " << _serial << " status : " << (_functionnal ? "OK" : "KO") << std::endl;
}
