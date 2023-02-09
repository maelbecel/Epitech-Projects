/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include "SharedPointer.hpp"

SharedPointer::SharedPointer()
{
}

SharedPointer::SharedPointer(IObject *obj)
{
    _obj = std::shared_ptr<IObject>(obj);
}

SharedPointer::SharedPointer(SharedPointer &obj)
{
    _obj = obj._obj;
}

SharedPointer::~SharedPointer()
{
}

void SharedPointer::touch()
{
    _obj->touch();
}

void SharedPointer::swap(SharedPointer &other)
{
    std::swap(_obj, other._obj);
}

void SharedPointer::reset(IObject *obj)
{
    _obj.reset(obj);
}

void SharedPointer::reset()
{
    _obj.reset();
}

int SharedPointer::use_count()
{
    return _obj.use_count();
}

SharedPointer &SharedPointer::operator=(SharedPointer &object)
{
    _obj = object._obj;
    return *this;
}

SharedPointer &SharedPointer::operator=(IObject *object)
{
    _obj = std::shared_ptr<IObject>(object);
    return *this;
}


IObject *SharedPointer::operator->()
{
    return _obj.get();
}

IObject &SharedPointer::operator*()
{
    return *_obj;
}