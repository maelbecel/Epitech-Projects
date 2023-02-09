/*
** EPITECH PROJECT, 2023
** uu
** File description:
** u
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer()
{
}

UniquePointer::UniquePointer(IObject *obj)
{
    _obj = std::unique_ptr<IObject>(obj);
}

UniquePointer::~UniquePointer()
{
}

void UniquePointer::touch()
{
    _obj->touch();
}

void UniquePointer::swap(UniquePointer &other)
{
    std::swap(_obj, other._obj);
}

void UniquePointer::reset(IObject *obj)
{
    _obj.reset(obj);
}

void UniquePointer::reset()
{
    _obj.reset();
}

UniquePointer &UniquePointer::operator=(IObject *object)
{
    _obj.reset(object);
    return *this;
}

IObject *UniquePointer::operator->()
{
    return _obj.get();
}

IObject &UniquePointer::operator*()
{
    return *_obj;
}
