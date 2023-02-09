/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH3-lucas.iglesia
** File description:
** Info
*/

#include "../include/Info.hpp"
#include <sys/utsname.h>
#include <unistd.h>
#include <limits.h>
#include <ctime>

/**
 * A constructor for the class Info.
 */
Info::Info() {}

/**
 * Destructor for Info class.
 */
Info::~Info() {}

/**
 * It returns the name of the operating system
 *
 * @return The name of the operating system.
 */
std::string Info::getOsName()
{
    struct utsname buffer;
    errno = 0;
    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    return buffer.sysname;
}

/**
 * It gets the hostname of the machine
 * 
 * @return The hostname of the machine.
 */
std::string Info::getHostname()
{
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    return hostname;
}

/**
 * It gets the user name of the current user
 *
 * @return The user name of the user running the program.
 */
std::string Info::getUserName()
{
    char user[LOGIN_NAME_MAX];
    getlogin_r(user, LOGIN_NAME_MAX);
    return user;
}

/**
 * It gets the kernel version
 *
 * @return The kernel version.
 */
std::string Info::getKernelVersion()
{
    struct utsname buffer;
    errno = 0;
    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    return buffer.release;
}

/**
 * It returns the current date and time
 *
 * @return A string containing the current date and time.
 */
std::string Info::getDateTime()
{
    time_t now = time(0);

    char* date_time = ctime(&now);

    return date_time;
}
