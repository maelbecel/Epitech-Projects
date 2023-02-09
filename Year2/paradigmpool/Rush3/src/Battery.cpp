/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Battery
*/

#include "../include/Battery.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>

/**
 * A constructor for the Battery class.
 */
Battery::Battery() {}

/**
 * The destructor is called when the object is destroyed.
 */
Battery::~Battery() {}

/**
 * It opens the file `/sys/class/power_supply/BAT0/uevent` and reads the line that
 * contains `POWER_SUPPLY_CAPACITY=` and returns the value after the equals sign
 *
 * @return The battery percentage.
 */
std::string Battery::getPercent()
{
    std::ifstream stream("/sys/class/power_supply/BAT0/uevent");
    std::string line = "";

    if (stream.is_open()) {
        while (getline(stream, line)) {
            if (line.find("POWER_SUPPLY_CAPACITY=") != std::string::npos) {
                line = line.substr(strlen("POWER_SUPPLY_CAPACITY="), line.length());
                return line;
            }
        }
    } else {
        std::ifstream stream("/sys/class/power_supply/BAT1/uevent");

        if (stream.is_open()) {
            while (getline(stream, line)) {
                if (line.find("POWER_SUPPLY_CAPACITY=") != std::string::npos) {
                    line = line.substr(strlen("POWER_SUPPLY_CAPACITY="), line.length());
                    return line;
                }
            }
        } else {
            return "0";
        }
    }
    return "0";
}
