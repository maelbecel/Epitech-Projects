/*
** EPITECH PROJECT, 2023
** d
** File description:
** d
*/

#include "SafeDirectoryLister.hpp"

std::string SafeDirectoryLister::get()
{
    struct dirent *entry;
    if (!_dir) {
        throw IDirectoryLister::OpenFailureException();
    }
    entry = readdir(_dir);
    if (entry) {
        if (entry->d_name[0] == '.' && !_hidden)
            return get();
        return entry->d_name;
    }
    throw IDirectoryLister::NoMoreFileException();
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden)
{
    if (_dir)
        closedir(_dir);
    DIR *dir = opendir(path.c_str());
    _dir = dir;
    _hidden = hidden;
    if (dir)
        return true;
    else {
        throw IDirectoryLister::OpenFailureException();
    }
}
