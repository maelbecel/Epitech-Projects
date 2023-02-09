/*
** EPITECH PROJECT, 2023
** toy
** File description:
** toy
*/

#include "ToyStory.hpp"
#include <list>
#include <fstream>

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

bool displayStory(Toy &toy, bool (Toy::*func)(std::string str), std::string happen, int &i)
{
    if (happen.find("picture:") == 0) {
        if (toy.setAscii(happen.erase(0, 8)))
            std::cout << toy.getAscii() << std::endl;
        else {
            std::cout << toy.getLastError().where() << ": " << toy.getLastError().what() << std::endl;
            return false;
        }
    } else {
        if ((toy.*func)(happen))
            i++;
        else {
            std::cout << toy.getLastError().where() << ": " << toy.getLastError().what() << std::endl;
            return false;
        }
    }
    return true;
}


void ToyStory::tellMeAStory(const std::string filename, Toy &toy1, bool (Toy::*func1)(const std::string str), Toy &toy2,  bool (Toy::*func2)(const std::string str))
{

    std::list <std::string> Story;
    std::string line;
    std::ifstream file(filename);
    int i = 0;

    if (!file.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        Story.push_back(line);
    }
    file.close();

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    for (std::string happen : Story) {
        if (i % 2 == 0) {
            if (!displayStory(toy1, func1, happen, i))
                return;
        } else {
            if (!displayStory(toy2, func2, happen, i))
                return;
        }
    }
}