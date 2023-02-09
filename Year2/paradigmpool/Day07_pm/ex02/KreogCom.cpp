/*
** EPITECH PROJECT, 2023
** Kreog
** File description:
** kreog
*/

#include "KreogCom.hpp"

KreogCom::KreogCom (int x , int y , int serial) : _x(x), _y(y), m_serial(serial), _next(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom (int x , int y , int serial )
{
    KreogCom *tmp = new KreogCom(x, y, serial);

    if (this->_next == nullptr)
        this->_next = tmp;
    else {
        tmp->_next = this->_next;
        this->_next = tmp;
    }
}

KreogCom *KreogCom::getCom(void)
{
    return this->_next;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = this->_next;

    if (this->_next != nullptr) {
        this->_next = this->_next->_next;
        delete tmp;
    }
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->_next;
    while (tmp->_next != nullptr) {
        tmp->ping();
        tmp = tmp->_next;
    }
}
