/*
** EPITECH PROJECT, 2023
** exam
** File description:
** exam
*/

#include "Exam.hpp"
#include <iostream>

bool Exam::cheat = false;

Exam::Exam(bool *ptr)
{
    cheat = ptr;
    Exam::cheat = false;
}

bool Exam::isCheating(void)
{
    return (Exam::cheat);
}

void Exam::start(int x)
{
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << x <<" Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;
    if (Exam::cheat)
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    else
        std::cout << "This exam is hard... you lost again." << std::endl;
}

Exam::~Exam()
{
}
