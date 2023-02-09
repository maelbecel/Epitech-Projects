/*
** EPITECH PROJECT, 2023
** l
** File description:
** l
*/

#include "List.hpp"

List::List()
{
}

List::~List()
{
}

bool List::empty() const
{
    return _obj.empty();
}

std::size_t List::size() const
{
    return _obj.size();
}

IObject*& List::front()
{
    if (_obj.empty())
        throw List::InvalidOperationException();
    return _obj.front();
}

IObject *List::front() const
{
    if (_obj.empty())
        throw List::InvalidOperationException();
    return _obj.front();
}

IObject*& List::back()
{
    if (_obj.empty())
        throw List::InvalidOperationException();
    return _obj.back();
}

IObject *List::back() const
{
    if (_obj.empty())
        throw List::InvalidOperationException();
    return _obj.back();
}
void List::pushBack(IObject* obj)
{
    _obj.push_back(obj);
}

void List::popFront()
{
    if (_obj.empty())
        throw List::InvalidOperationException();
    _obj.pop_front();
}

void List::pushFront(IObject* obj)
{
    _obj.push_front(obj);
}

void List::popBack()
{
    if (_obj.empty())
        throw List::InvalidOperationException();
    _obj.pop_back();
}

void List::clear()
{
    for (IObject *obj : _obj)
        delete obj;
    _obj.clear();
}

void List::forEach(void(*function)(IObject*))
{
    for (IObject *obj : _obj)
        function(obj);
}
