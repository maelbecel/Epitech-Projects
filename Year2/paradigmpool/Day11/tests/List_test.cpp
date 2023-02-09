/*
** EPITECH PROJECT, 2023
** h
** File description:
** h
*/

#include <criterion/criterion.h>
#include "../List.hpp"

class TestObject : public IObject
{
    public:
        TestObject ( const std :: string & name ) : _name ( name ) { std :: cout << _name << " is alive"<<  std :: endl ; }
        ~TestObject () { std :: cout << _name << " is dead"<<  std :: endl ; }
        void touch () { std :: cout << _name << " is touched"<<  std :: endl ; }
    private:
        std :: string _name ;
};

Test(List_create, get_new_list)
{
    List *list = new List();

    cr_assert_not_null(list);
    cr_assert_eq(list->size(), 0);
}

Test(List_empty, check_empty_list)
{
    List *list = new List();

    cr_assert_eq(list->empty(), true);
    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    cr_assert_eq(list->size(), 1);
    cr_assert_eq(list->empty(), false);
}

Test(List_size, check_list_size)
{
    List *list = new List();

    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    cr_assert_eq(list->size(), 1);
}

Test(List_push_back, check_list_push_back)
{
    List *list = new List();

    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    cr_assert_eq(list->size(), 1);
}

Test(List_push_front, check_list_push_front)
{
    List *list = new List();

    cr_assert_eq(list->size(), 0);
    list->pushFront(new TestObject("Bob"));
    cr_assert_eq(list->size(), 1);
}

Test(List_pop_back, check_list_pop_back)
{
    List *list = new List();

    try {
        list->popBack();
    } catch (const List::InvalidOperationException &e) {
        cr_assert_eq(list->size(), 0);
    }
    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    cr_assert_eq(list->size(), 1);
    list->popBack();
    cr_assert_eq(list->size(), 0);
}

Test(List_pop_front, check_list_pop_front)
{
    List *list = new List();

    try {
        list->popFront();
    } catch (const List::InvalidOperationException &e) {
        cr_assert_eq(list->size(), 0);
    }
    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    cr_assert_eq(list->size(), 1);
    list->popFront();
    cr_assert_eq(list->size(), 0);
}

Test(List_clear, clear_list)
{
    List *list = new List();

    list->clear();
    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    list->pushBack(new TestObject("Bob"));
    list->pushBack(new TestObject("Bob"));
    cr_assert_eq(list->size(), 3);
    list->clear();
}

void assertname(IObject *obj)
{
    obj->touch();
}

Test(List_forEach, forEach_list)
{
    List *list = new List();

    cr_assert_eq(list->size(), 0);
    list->forEach(assertname);
    list->pushBack(new TestObject("Bob"));
    list->pushBack(new TestObject("Bob"));
    list->pushBack(new TestObject("Bob"));
    list->forEach(assertname);

    List list2;
    list2.pushBack(new TestObject("Bob"));
    list2.pushBack(new TestObject("Bob"));
    list2.pushBack(new TestObject("Bob"));
    list2.forEach(assertname);
}

Test(List_front, front_of_List)
{
    List *list = new List();

    try {
        list->front();
    } catch (const List::InvalidOperationException &e) {
        cr_assert_eq(list->size(), 0);
    }
    try {
        list->front ()= new TestObject("PAsbob");
    } catch (const List::InvalidOperationException &e) {
        cr_assert_eq(list->size(), 0);
    }
    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    list->pushBack(list->front());
    list->front ()= new TestObject("PAsbob");
    list->front();
}

Test(List_back, back_of_List)
{
    List *list = new List();

    try {
        list->back();
    } catch (const List::InvalidOperationException &e) {
        cr_assert_eq(list->size(), 0);
    }
    cr_assert_eq(list->size(), 0);
    list->pushBack(new TestObject("Bob"));
    list->pushBack(list->back());
    list->back();
}

Test(List_dest, destruct_a_list)
{
    List list;
}