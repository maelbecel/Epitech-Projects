/*
** EPITECH PROJECT, 2023
** Student.cpp
** File description:
** Student
*/

#include "Student.hpp"
#include "Assistant.hpp"

// ============================================================================
//                                    Student
// ============================================================================

Student::Student(std::string name) : _name(name), _energy(100)
{
    std::cout << "Student " << this->_name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << this->_name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

std::string replaceAll(std::string str, const std::string &from, const std::string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

bool Student::learn(std::string text)
{
    if (this->_energy >= 42) {
        this->_energy -= 42;
        std::cout << "Student " << this->_name << ": " << text << std::endl;
        return true;
    }
    std::cout << "Student " << this->_name << ": " << replaceAll(text, "C++", "shit") << std::endl;
    return false;
}

std::string Student::getName(void)
{
    return this->_name;
}

void Student::drink(std::string drink)
{
    if (drink == "Red Bull") {
        std::cout << "Student " << this->_name << ": Red Bull gives you wings!" << std::endl;
        this->_energy = FILL(this->_energy, 32);
    } else if (drink == "Monster") {
        std::cout << "Student " << this->_name << ": Unleash The Beast!" << std::endl;
        this->_energy = FILL(this->_energy, 64);
    } else {
        std::cout << "Student " << this->_name << ": ah, yes... enslaved moisture." << std::endl;
        this->_energy = FILL(this->_energy, 1);
    }
}
