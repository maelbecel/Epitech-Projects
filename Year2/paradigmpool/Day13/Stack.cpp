/*
** EPITECH PROJECT, 2023
** stack
** File description:
** stack
*/

#include "Stack.hpp"

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop()
{
    if (_stack.empty())
        throw Error("Empty stack");
    double value = _stack.top();
    _stack.pop();
    return value;
}

double Stack::top()
{
    if (_stack.empty())
        throw Error("Empty stack");
    return _stack.top();
}

void Stack::add()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double value1 = pop();
    double value2 = pop();
    push(value1 + value2);
}

void Stack::sub()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double value1 = pop();
    double value2 = pop();
    push(value1 - value2);
}

void Stack::mul()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double value1 = pop();
    double value2 = pop();
    push(value1 * value2);
}

void Stack::div()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double value1 = pop();
    double value2 = pop();
    if (value2 == 0)
        throw Error("Division by 0");
    push(value1 / value2);
}