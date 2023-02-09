/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Network
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Network.hpp"

/**
 * This function is the constructor for the Network class. It calls the updateIp()
 * and getNetworkInfo() functions.
 */
Network::Network()
{
    updateIp();
    getNetworkInfo();
}

/**
 * The destructor for the Network class.
 */
Network::~Network() {}

/**
 * It returns the host name for the local computer
 *
 * @param hostname This is the host name of the local computer.
 */
static void check_host_name(int hostname) { //This function returns host name for local computer
    if (hostname == -1) {
        perror("gethostname");
        exit(1);
    }
}

/**
 * It takes a host name and returns a host entry
 *
 * @param hostentry a pointer to a hostent structure, which contains information
 * about the host.
 */
static void check_host_entry(struct hostent * hostentry) {
    if (hostentry == NULL){
        perror("gethostbyname");
        exit(1);
    }
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

/**
 * It gets the IP address of the machine it's running on
 */
void Network::updateIp()
{
    char host[256];
    char *IP;
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(host, sizeof(host));
    check_host_name(hostname);
    host_entry = gethostbyname(host);
    check_host_entry(host_entry);
    IP = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));
    _ip = IP;
}

/**
 * It reads the /proc/net/dev file and calculates the difference between the
 * current values and the previous values
 */
void Network::getNetworkInfo()
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    std::string value;
    size_t pos = 0;
    int i = 0;
    size_t dlByte = 0;
    size_t dlPack = 0;
    size_t upByte = 0;
    size_t upPack = 0;

    if (file.is_open()) {
        getline(file, line);
        getline(file, line);
        while (getline(file, line)) {
            line = line.substr(line.find(":") + 1, line.size());
            while ((pos = line.find(" ")) != std::string::npos) {
                value = line.substr(0, pos);
                if (value != "") {
                    if (i == 0) {
                        dlByte += atol(value.c_str());
                    } else if (i == 1) {
                        dlPack += atol(value.c_str());
                    } else if (i == 8) {
                        upByte += atol(value.c_str());
                    } else if (i == 9) {
                        upPack += atol(value.c_str());
                    }
                    i++;
                }
                line.erase(0, pos + 1);
            }
            i = 0;
        }
        file.close();
    }
    _valueSec[0] = dlByte - atol(_networkValues[0].c_str());
    _valueSec[1] = dlPack - atol(_networkValues[1].c_str());
    _valueSec[2] = upByte - atol(_networkValues[2].c_str());
    _valueSec[3] = upPack - atol(_networkValues[3].c_str());
    _networkValues[0] = sToStr(dlByte);
    _networkValues[1] = sToStr(dlPack);
    _networkValues[2] = sToStr(upByte);
    _networkValues[3] = sToStr(upPack);
}

/**
 * It updates the IP address and network information
 */
void Network::Update(void)
{
    updateIp();
    getNetworkInfo();
}

/**
 * It returns a map of strings, where the key is the name of the data and the
 * value is the data itself
 *
 * @return A map of strings.
 */
std::map<std::string, std::string> Network::getData(void)
{
    std::map<std::string, std::string> res;
    res["ip"] = _ip;
    res["downloadBytes"] = sToStr(_valueSec[0]);
    res["downloadPackets"] = sToStr(_valueSec[1]);
    res["uploadBytes"] = sToStr(_valueSec[2]);
    res["uploadPackets"] = sToStr(_valueSec[3]);
    return res;
}
