/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Memory
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/Memory.hpp"


/**
 * It opens the /proc/meminfo file, reads it line by line, and if it finds the
 * line that contains the value we're looking for, it returns the value
 *
 * @param value The value we want to get from the file.
 *
 * @return The total amount of RAM in the system.
 */
static std::string getMemInfo(std::string value)
{
    std::string ramSize;
    std::ifstream file("/proc/meminfo");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(value) != std::string::npos) {
                ramSize = line.substr(line.find(":") + 2, line.find("kB") - 3);
                break;
            }
        }
        file.close();
    }
    return ramSize;
}

/**
 * It converts a size_t to a string
 *
 * @param x the number to convert to a string
 *
 * @return A string
 */
static std::string sToStr(size_t x)
{
    std::string str;
    std::stringstream ss;
    ss << x;
    str = ss.str();
    return str;
}

// ============================================================================
//                                InfoMemory
// ============================================================================

/**
 * The InfoMemory constructor takes a string as an argument and assigns it to the
 * _name member variable. It then calls the getMemInfo function and passes the
 * _name member variable to it. The getMemInfo function returns a string which is
 * converted to an unsigned long and assigned to the _value member variable.
 *
 * @param name The name of the memory type you want to get the value of.
 */
InfoMemory::InfoMemory(const std::string name)
{
    _name = name;
    _value = std::stoul(getMemInfo(name));
}

/**
 * GetValue returns the value of the _value member variable.
 *
 * @return The value of the variable _value.
 */
size_t InfoMemory::GetValue(void) const
{
    return _value;
}

/**
 * This function sets the value of the InfoMemory object.
 *
 * @param value The value to set the memory to.
 */
void InfoMemory::SetValue(const size_t &value)
{
    _value = value;
}

// ============================================================================
//                                RAM
// ============================================================================


/**
 * It reads the current memory and swap usage from the system, and updates the
 * corresponding member variables
 */
void RAM::Update(void)
{
    size_t currentMem = std::atol(getMemInfo("MemTotal").c_str()) -
                        std::atol(getMemInfo("MemAvailable").c_str());

    size_t currentSwap = std::atol(getMemInfo("SwapTotal").c_str()) -
                         std::atol(getMemInfo("SwapFree").c_str());

    _memTotal.SetValue(std::stoul(getMemInfo("MemTotal")));
    _memCurrent.SetValue(currentMem);
    _swapTotal.SetValue(std::stoul(getMemInfo("SwapTotal")));
    _swapCurrent.SetValue(currentSwap);
}

/**
 * It returns the total amount of memory.
 *
 * @return The total amount of memory in the system.
 */
InfoMemory RAM::GetMemTotal(void) const
{
    return _memTotal;
}

/**
 * > This function returns the current memory usage
 *
 * @return A struct of type MemInfoMemory
 */
InfoMemory RAM::GetMemCurrent(void) const
{
    return _memCurrent;
}

/**
 * This function returns the total amount of swap memory.
 *
 * @return The total amount of swap memory.
 */
InfoMemory RAM::GetSwapTotal(void) const
{
    return _swapTotal;
}

/**
 * Get the current swap
 *
 * @return The current swap memory usage.
 */
InfoMemory RAM::GetSwapCurrent(void) const
{
    return _swapCurrent;
}

/**
 * It returns a map of strings to strings, where the first string is the name of
 * the data, and the second string is the value of the data
 *
 * @return A map of strings to strings.
 */
std::map<std::string, std::string> RAM::getData(void)
{
    std::map<std::string, std::string> res;
    res["MemTotal"] = sToStr(_memTotal.GetValue());
    res["SwapTotal"] = sToStr(_swapTotal.GetValue());
    res["MemCurrent"] = sToStr(_memCurrent.GetValue());
    res["SwapCurrent"] = sToStr(_swapCurrent.GetValue());
    return res;
}