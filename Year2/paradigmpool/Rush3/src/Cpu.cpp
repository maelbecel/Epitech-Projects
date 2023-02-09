/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Cpu
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Cpu.hpp"

/**
 * It opens the file /proc/cpuinfo, reads each line, and if the line contains the
 * string "MemTotal", it extracts the value of the memory size from the line and
 * returns it
 *
 * @param value The value we want to get from the file.
 *
 * @return the value of the cpuinfo file.
 */
static std::string getCpuInfo(const std::string value)
{
    std::string ramSize;
    std::ifstream file("/proc/cpuinfo");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(value) != std::string::npos) {
                ramSize = line.substr(line.find(":") + 2, line.find("kB") - 3);
            }
        }
        file.close();
    }
    return ramSize;
}

/**
 * It opens the /proc/stat file, reads each line, and if the line contains the
 * value passed to the function, it returns the value after the colon and before
 * the kB
 *
 * @param value The value to search for in the file.
 *
 * @return the value of the line that contains the value passed in.
 */
static std::string getProcessInfo(const std::string value)
{
    std::string ramSize;
    std::ifstream file("/proc/stat");
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
 * It reads the first line of a file and returns the number it contains
 *
 * @param filename the name of the file to read from
 *
 * @return The number of lines in the file.
 */
static size_t nbFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    size_t nb = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            nb = std::atol(line.c_str());
        }
        file.close();
    }
    return nb;
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
//                                Core
// ============================================================================

/**
 * It reads the /proc/stat file and calculates the percentage of CPU usage
 *
 * @param core The core number to get the usage of.
 */
void Core::UpdateUsage(int core){
    double percent = 0;
    size_t totalUser = 0;
    size_t totalUserLow = 0;
    size_t totalSys = 0;
    size_t totalIdle = 0;
    size_t total = 0;
    std::ifstream file("/proc/stat");
    std::string line = "";

    for (int i = 0; i < core + 1 && getline(file, line); i++);
    if (getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;
        iss >> totalUser;
        iss >> totalUserLow;
        iss >> totalSys;
        iss >> totalIdle;
    }

    if (totalUser < _lastTotalUser || totalUserLow < _lastTotalUserLow ||
        totalSys < _lastTotalSys || totalIdle < _lastTotalIdle){
        percent = 0;
    }
    else{
        total = (totalUser - _lastTotalUser) + (totalUserLow - _lastTotalUserLow) +
            (totalSys - _lastTotalSys);
        percent = total;
        total += (totalIdle - _lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    _lastTotalUser = totalUser;
    _lastTotalUserLow = totalUserLow;
    _lastTotalSys = totalSys;
    _lastTotalIdle = totalIdle;
    _usage = percent;
}

// ============================================================================
//                                Cpu
// ============================================================================

/**
 * We read the first line of the file `/proc/stat` and parse it to get the total
 * user, user low, system, and idle times. We then calculate the percentage of
 * time the CPU has been used since the last time we called this function
 */
void CPU::UpdateUsage(){
    double percent;
    size_t totalUser;
    size_t totalUserLow;
    size_t totalSys;
    size_t totalIdle;
    size_t total;
    std::ifstream file("/proc/stat");
    std::string line;
    if (getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;
        iss >> totalUser;
        iss >> totalUserLow;
        iss >> totalSys;
        iss >> totalIdle;
    }

    if (totalUser < _lastTotalUser || totalUserLow < _lastTotalUserLow ||
        totalSys < _lastTotalSys || totalIdle < _lastTotalIdle){
        percent = 0;
    }
    else{
        total = (totalUser - _lastTotalUser) + (totalUserLow - _lastTotalUserLow) +
            (totalSys - _lastTotalSys);
        percent = total;
        total += (totalIdle - _lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    _lastTotalUser = totalUser;
    _lastTotalUserLow = totalUserLow;
    _lastTotalSys = totalSys;
    _lastTotalIdle = totalIdle;
    _usage = percent;
}


/**
 * It initializes the CPU class by getting the model name, the number of cores,
 * the maximum frequency and the cores
 */
CPU::CPU()
{
    _model = getCpuInfo("model name");
    _nbCore = std::stoi(getCpuInfo("processor")) + 1;
    _maxFrequence = nbFromFile("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq") / 1000 * _nbCore;
    _core = new Core[_nbCore];
    Update();
}

/**
 * The destructor for the CPU class.
 */
CPU::~CPU()
{
    delete[] _core;
}

/**
 * It reads the file /proc/cpuinfo and extracts the CPU frequency for each core
 */
void CPU::UpdateCore(void)
{
    std::string ramSize;
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string l;
    int i = 0;

    if (file.is_open()) {
        while (getline(file, line) && size_t(i) < _nbCore) {
            if (line.find("cpu MHz") != std::string::npos) {
                l = line.substr(line.find(":") + 2, line.find("kB") - 3);
                _core[i].SetActivity(std::atol(l.c_str()));
                i++;
            }
        }
        file.close();
    }
}

/**
 * It updates the CPU usage and the number of running processes
 */
void CPU::Update(void)
{
    UpdateCore();
    UpdateUsage();
    _nbProcess = std::atol(getProcessInfo("procs_running").c_str());
/**
 * It draws the network window
 *
 * @param win The window to draw on.
 */
    _frequence = 0;
    for (size_t i = 0; i < _nbCore; i++) {
        _frequence += _core[i].GetActivity();
        _core[i].UpdateUsage(i);
    }
}

/**
 * It returns a map of strings, which contains the CPU's usage, model, frequence,
 * number of processes, maximum frequence and number of cores
 *
 * @return A map of strings
 */
std::map<std::string, std::string> CPU::getData(void)
{
    std::map<std::string, std::string> res;
    res["usage"] = sToStr(_usage);
    res["model"] = _model;
    res["frequence"] = sToStr(_frequence);
    res["nbProcess"] = sToStr(_nbProcess);
    res["maxFrequence"] = sToStr(_maxFrequence);
    res["nbCore"] = sToStr(_nbCore);
    return res;
}
