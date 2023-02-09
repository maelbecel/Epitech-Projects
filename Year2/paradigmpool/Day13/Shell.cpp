/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGD13-mael1.becel
** File description:
** Shell
*/

#include "Shell.hpp"

Shell::Shell(std::istream &stream) : _stream(stream) {}

Shell::~Shell()
{
}

void Shell::next()
{
    if (_stream.peek() == EOF)
        throw Error("End of file");
    if (_stream.bad())
        throw Error("Input failed");
    std::string line;
    std::getline(_stream, line);
    _buffer.str(line);
    _buffer.clear();
}
