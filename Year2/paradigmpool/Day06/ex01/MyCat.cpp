/*
** EPITECH PROJECT, 2023
** paradigmpool
** File description:
** day6 ex00
*/

#include <iostream>
#include <string>
#include <fstream>

/**
 * It opens a file, reads it line by line and prints it to the standard output
 *
 * @param argc The number of arguments passed to the program.
 * @param f The file to read
 *
 * @return The return value of the function.
 */
int MyCat(int argc, char *f)
{
    std::string line;
    std::ifstream file(f);

    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "MyCat: " << f << ": No such file or directory" << std::endl;
        return 84;
    }
    return 0;
}

/**
 * It opens a file, reads it, and prints it to the standard output
 *
 * @param argc The number of arguments passed to the program.
 * @param argv the array of arguments
 *
 * @return The return value of the function.
 */
int main(int argc, char *argv[])
{
    std::string line;

    if (argc == 1) {
        while (getline(std::cin, line)) {
            std::cout << line << std::endl;
        }
    }
    for (int i = 1; i < argc; i++) {
        if (MyCat(argc, argv[i]) != 0)
            return 84;
    }
    return 0;
}