/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGD13-mael1.becel
** File description:
** Command
*/

#include "Command.hpp"

Command::Command()
{
}

Command::~Command()
{
}

void Command::registerCommand ( const std :: string & name , const std :: function < void () >&function )
{
    if (_commands.find(name) != _commands.end())
        throw Error("Already registered command");
    _commands[name] = function;
}

void Command::executeCommand ( const std :: string & name )
{
    if (_commands.find(name) == _commands.end())
        throw Error("Unknow command");
    _commands[name]() ;
}