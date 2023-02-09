/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include <criterion/criterion.h>
#include "../UniquePointer.hpp"
#include <iostream>

class TestObject : public IObject
{
    public:
        TestObject ( const std :: string & name ) : _name ( name ) { std :: cout << _name << " is alive"<<  std :: endl ; }
        ~TestObject () { std :: cout << _name << " is dead"<<  std :: endl ; }
        void touch () { std :: cout << _name << " is touched"<<  std :: endl ; }
    private:
        std :: string _name ;
};

Test(UniquePointer_i, Create_UniquePointer)
{
    UniquePointer p1;
    UniquePointer p2(new TestObject("Bob"));
}

Test(UniquePointer_touch, touch_from_UniquePointer)
{
    UniquePointer p1;
    UniquePointer p2(new TestObject("Bob"));
    p2->touch();
    p2.touch();
}

Test(UniquePointer_swap, swap_UniquePointer)
{
    UniquePointer p1;
    UniquePointer p2(new TestObject("Bob"));
    p1.swap(p2);
    p2.swap(p1);
}

Test(UniquePointer_reset, reset_UniquePointer)
{
    UniquePointer p1;
    UniquePointer p2(new TestObject("Bob"));
    p1.reset(new TestObject("Bob"));
    p2.reset();
}

Test(UniquePointer_operator_equal, operator_equal_UniquePointer)
{
    UniquePointer p1;
    UniquePointer p2(new TestObject("Bob"));
    p1 = new TestObject("Bob");
}

Test(UniquePointer_operator_deref, deref_UniquePointer)
{
    UniquePointer p1;
    UniquePointer p2(new TestObject("Bob"));
    (*p2).touch();
    p2->touch();
}