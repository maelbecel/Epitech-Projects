/*
** EPITECH PROJECT, 2023
** paradigmpool
** File description:
** day6 ex00
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


#define CELSIUS(a)  5.0 / 9.0 * ( a - 32 )
#define FAHRENHEIT(a)  a * (9.0 / 5.0) + 32

bool IsFloat (std::string string)
{
    try {
        std::stof (string);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

void Display (std::string val, std::string unit)
{
    float value;
    if (!IsFloat(val))
        return;
    value = std::stof (val);
    if (unit == "Celsius") {
        std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(3) << FAHRENHEIT (value) << std::right << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (unit == "Fahrenheit") {
        std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(3) << CELSIUS (value)  << std::right << std::setw(16) << "Celsius" << std::endl;
    }
}

std::string *SplitLine (std::string line)
{
    std::string *tab = new std::string[2];
    int i = 0;
    int j = 0;
    for (;line[i] == ' '; i++);
    while (line[i] != ' ') {
        tab[0] += line[i];
        i++;
    }
    for (;line[i] == ' '; i++);
    while (line[i] != '\0') {
        tab[1] += line[i];
        i++;
    }
    return tab;
}

int main(void)
{
    std::string line;
    std::string value;
    std::string unit;

    while (getline(std::cin, line)) {
        std::stringstream lines(line);
        lines >> value >> unit;
        Display(value, unit);
    }
    return 0;
}