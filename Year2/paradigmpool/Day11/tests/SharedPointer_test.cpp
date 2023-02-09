/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include <criterion/criterion.h>
#include "../SharedPointer.hpp"
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

Test(SharedPointer_i, SharedPointer_init)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    SharedPointer p3(p);
    SharedPointer p4(p2);
}

Test(SharedPointer_touch, SharedPointer_touche)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    p2->touch();
    p = p2;
    p.touch();
}

Test(SharedPointer_swap, Swap_pointers)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    SharedPointer p3(p);
    SharedPointer p4(p2);
    p.swap(p2);
    p2.swap(p4);
}

Test(SharedPointer_reset, Reset_Pointers)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    SharedPointer p3(p);
    SharedPointer p4(p2);
    p.reset();
    p2.reset(new TestObject("Jej"));
}

Test(SharedPointer_use_count, UseCount_on_ptrs)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    SharedPointer p3(p);
    SharedPointer p4(p2);
    cr_assert_eq(p.use_count(), 0);
    cr_assert_eq(p2.use_count(), 2);
}

Test(SharedPointer_eq_operator, Equal_operator_on_sharedptrs)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    SharedPointer p4(p2);
    p2 = new TestObject("JEJEJE");
    p = p2;
    p4 = p;
}

Test(SharedPointer_unref_operator, Unreference_operator_on_sharedptrs)
{
    SharedPointer p;
    SharedPointer p2(new TestObject("Pedro"));
    SharedPointer p4(p2);
    (*p2).touch();
    (*p4).touch();
}
