/*
** EPITECH PROJECT, 2023
** Student.cpp
** File description:
** Student
*/

#include "Student.hpp"
#include "Assistant.hpp"

// ============================================================================
//                                    Assistant
// ============================================================================

Assistant::Assistant(int i) : _id(i), _isWorking(false)
{
    std::cout << "Assistant " << this->_id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << this->_id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, std::string drink)
{
    std::cout << "Assistant " << this->_id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(drink);
}

int Assistant::getId()
{
    return _id;
}

std::string Assistant::readDrink(std::string student)
{
    std::string filename = student + ".drink";
    const char *fn = filename.c_str();
    std::ifstream file(filename);
    std::string line;

    if (file.is_open() && !file.eof()) {
        getline(file, line);
        std::stringstream lines(line);
        file.close();
        if (lines.str() == "")
            return "";
        std::cout << "Assistant " << this->_id << ": " << student << " needs a " << lines.str() << " *sip coffee*" << std::endl;
        std::remove(fn);
        return lines.str();
    } else {
        return "";
    }
}

void Assistant::helpStudent(Student *student)
{
    std::string drink = this->readDrink(student->getName());

    if (drink == "")
        std::cout << "Assistant " << this->_id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
    else
        giveDrink(student, drink);
}

void Assistant::timeCheck(void)
{
    if (!this->_isWorking)
        std::cout << "Assistant " << this->_id << ": Time to teach some serious business *sip coffee*" << std::endl;
    else
        std::cout << "Assistant " << this->_id << ": Enough teaching for today *sip coffee*" << std::endl;
    this->_isWorking = !this->_isWorking;
}
