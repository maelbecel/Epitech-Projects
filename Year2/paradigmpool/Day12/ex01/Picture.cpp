/*
** EPITECH PROJECT, 2023
** pi
** File description:
** p
*/

#include "Picture.hpp"
#include <fstream>


Picture::Picture()
{
    data = "";
}

Picture::Picture(Picture &picture)
{
    data = picture.data;
}

Picture::Picture(const std :: string & file)
{
    if (!getPictureFromFile(file))
        data = "ERROR";
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream ifs(file);
    std::string str;

    if (ifs.is_open()) {
        while (getline(ifs, str))
            data += str + "\n";
        return true;
    }
    return false;
}

Picture &Picture::operator=(Picture &picture)
{
    data = picture.data;
    return *this;
}