/*
** EPITECH PROJECT, 2023
** Koalabot
** File description:
** koalabot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial) {}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = arms;
    arms = _arms;
    _arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = legs;
    legs = _legs;
    _legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = head;
    head = _head;
    _head = tmp;
}

void KoalaBot::informations(void)
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status(void)
{
    return _arms.isFunctionnal() && _legs.isFunctionnal() && _head.isFunctionnal();
}