/*
** EPITECH PROJECT, 2023
** dir
** File description:
** dir
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister() : _hidden(false), _dir(nullptr)
{
}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden) : _hidden(hidden), _dir(nullptr)
{
    DirectoryLister::open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (_dir)
        closedir(_dir);
}

bool DirectoryLister::open(const std::string& path, bool hidden)
{
    if (_dir)
        closedir(_dir);
    DIR *dir = opendir(path.c_str());
    _dir = dir;
    _hidden = hidden;
    if (dir)
        return true;
    else {
        perror(path.c_str());
        return false;
    }
}

std::string DirectoryLister::get()
{
    struct dirent *entry;
    if (!_dir)
        return "";
    entry = readdir(_dir);
    if (entry) {
        if (entry->d_name[0] == '.' && !_hidden)
            return get();
        return entry->d_name;
    }
    return "";
}
