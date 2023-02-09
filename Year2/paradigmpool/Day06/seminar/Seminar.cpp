/*
** EPITECH PROJECT, 2023
** seminar
** File description:
** seminar
*/

#include "Seminar.hpp"

Seminar::Seminar()
{
    this->_deans = std::vector<Dean *>();
    this->_students = std::vector<Student *>();
    this->_assistants = std::vector<Assistant *>();
}

Seminar::~Seminar()
{
}

void Seminar::showSeminar(void)
{
    std::cout << "Dean of Studies: " << _deans[0]->getName() << std::endl;
    std::cout << "Teaching assistants: ";
    for (size_t i = 0; i < _assistants.size(); i++) {
        std::cout << _assistants[i]->getId();
        if (i != _assistants.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
    std::cout << "Students: ";
    for (size_t i = 0; i < _students.size(); i++) {
        std::cout << _students[i]->getName();
        if (i != _students.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int move(int a, int list)
{
    if (list == 1)
        return a;
    else
        return !a;
}

void Seminar::run(void)
{
    int a = 0;

    if (!_deans.size() || !_students.size() || !_assistants.size()) {
        std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student." << std::endl;
        return;
    }
    std::cout << "Seminar: Begining 6th day of seminar." << std::endl;
    this->showSeminar();
    _deans[0]->timeCheck();
    for (int i = 0; i < _assistants.size(); _assistants[i]->timeCheck(), i++);

    for (int x = 0; x < 5; x++) {
        for (int i = 0; i < _students.size(); i++) {
            _deans[0]->teachStudent(_students[i], "I'm learning C++!");
            _assistants[a]->helpStudent(_students[i]);
            a = (_assistants.size() == 1) ? a : !a;
        }
    }
    _deans[0]->timeCheck();
    for (int i = 0; i < _assistants.size(); _assistants[i]->timeCheck(), i++);
}

void Seminar::addDean(Dean *dean)
{
    if (std::count(_deans.begin(), _deans.end(), dean))
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;
    else if (_deans.size() == 0) {
        _deans.push_back(dean);
        std::cout << "Seminar: Dean " << dean->getName() << " is here." << std::endl;
    } else
        std::cout << "Seminar: There can only be one Dean of Studies." << std::endl;

}

void Seminar::addStudent(Student *student)
{
    if (std::count(_students.begin(), _students.end(), student))
        std::cout << "Seminar: Student " << student->getName() << " is already registered." << std::endl;
    else if (_students.size() < 5) {
        _students.push_back(student);
        std::cout << "Seminar: Student " << student->getName() << " joined the seminar." << std::endl;
    } else
        std::cout << "Seminar: There is only room for five Students." << std::endl;

}

void Seminar::addAssistant(Assistant *assistant)
{
    if (std::count(_assistants.begin(), _assistants.end(), assistant))
        std::cout << "Seminar: Assistant " << assistant->getId() << " is already registered." << std::endl;
    else if (_assistants.size() < 2) {
        _assistants.push_back(assistant);
        std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team." << std::endl;
    } else
        std::cout << "Seminar: There is only room for two Teaching Assistants." << std::endl;

}