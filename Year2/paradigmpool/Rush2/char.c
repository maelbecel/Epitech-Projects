/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct {
    Class   base;
    char x;
}   CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid pointer");
    this->x = (char)va_arg(*args, int);
}

static const char *char_str(CharClass *this)
{
    static char buf[14];

    if (!this)
        raise("Invalid pointer");
    snprintf(buf, 14, "<Char (%c)>", this->x);
    return (strdup(buf));
}

static void char_dtor(CharClass *this)
{
    (void)this;
}

static Object *char_add(const Object *this, const Object *obj)
{
    CharClass *res = NULL;
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);
    int x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x + my_obj->x;
    res = new(Char, x);
    return (res);
}

static Object *char_sub(const Object *this, const Object *obj)
{
    CharClass *res = NULL;
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);
    int x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x - my_obj->x;
    res = new(Char, x);
    return (res);
}

static Object *char_mul(const Object *this, const Object *obj)
{
    CharClass *res = NULL;
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);
    int x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x * my_obj->x;
    res = new(Char, x);
    return (res);
}

static Object *char_div(const Object *this, const Object *obj)
{
    CharClass *res = NULL;
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);
    int x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    if (my_obj->x == 0)
        raise("Division by zero");
    x = my_this->x / my_obj->x;
    res = new(Char, x);
    return (res);
}

static bool char_eq(const Object *this, const Object *obj)
{
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->x == my_obj->x);
}

static bool char_gt(const Object *this, const Object *obj)
{
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->x > my_obj->x);
}

static bool char_lt(const Object *this, const Object *obj)
{
    CharClass *my_this = (CharClass *)(this);
    CharClass *my_obj = (CharClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->x < my_obj->x);
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_str,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;
