/*
** EPITECH PROJECT, 2023
** Dean
** File description:
** dean
*/

#include "Dean.hpp"

// ============================================================================
//                                    Dean
// ============================================================================

Dean::Dean(std::string name) : _name(name), _isWorking(false)
{
    std::cout << "Dean " << _name << ": I'm Dean " << _name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << _name << ": Time to go home." << std::endl;
}

std::string Dean::getName(void)
{
    return _name;
}

void Dean::teachStudent(Student *student, std::string lesson)
{
    const std::string Drinks[5] = {
        "Cristaline",
        "Monster",
        "Evian",
        "Red Bull",
        "Sierra Springs"
    };

    std::string filename = student->getName() + ".drink";
    std::string drink;
    const char *fn = filename.c_str();

    if (!student->learn(lesson)) {
        drink = Drinks[std::rand()% 5];
        std::cout << "Dean " << this->_name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;
        std::ofstream file(filename);
        file << drink;
        file.close();
        return;
    }
}

void Dean::timeCheck(void)
{
    if (!this->_isWorking)
        std::cout << "Dean " << this->_name << ": Where is everyone?" << std::endl;
    else
        std::cout << "Dean " << this->_name << ": Don't forget to close the windows when you leave." << std::endl;
    this->_isWorking = !this->_isWorking;
}
