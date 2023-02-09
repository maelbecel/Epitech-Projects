/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH2-lucas.iglesia
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct {
    Class base;
    int i;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid pointer");
    this->i = va_arg(*args, int);
}

static const char *int_str(IntClass *this)
{
    static char buf[21];

    if (!this)
        raise("Invalid pointer");
    snprintf(buf, 21, "<Int (%d)>", this->i);
    return (strdup(buf));
}

static void int_dtor(IntClass *this)
{
    (void)this;
}

static Object *int_add(const Object *this, const Object *obj)
{
    IntClass *res = NULL;
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);
    int i;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    i = my_this->i + my_obj->i;
    res = new(Int, i);
    return (res);
}

static Object *int_sub(const Object *this, const Object *obj)
{
    IntClass *res = NULL;
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);
    int i;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    i = my_this->i - my_obj->i;
    res = new(Int, i);
    return (res);
}

static Object *int_mul(const Object *this, const Object *obj)
{
    IntClass *res = NULL;
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);
    int i;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    i = my_this->i * my_obj->i;
    res = new(Int, i);
    return (res);
}

static Object *int_div(const Object *this, const Object *obj)
{
    IntClass *res = NULL;
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);
    int i;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    if (my_obj->i == 0)
        raise("Divsion by 0");
    i = my_this->i / my_obj->i;
    res = new(Int, i);
    return (res);
}

static bool int_eq(const Object *this, const Object *obj)
{
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->i == my_obj->i);
}

static bool int_gt(const Object *this, const Object *obj)
{
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->i > my_obj->i);
}

static bool int_lt(const Object *this, const Object *obj)
{
    IntClass *my_this = (IntClass *)(this);
    IntClass *my_obj = (IntClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->i < my_obj->i);
}

static const IntClass _description = {
    {
    .__size__ = sizeof(IntClass),
    .__name__ = "Int",
    .__ctor__ = (ctor_t)&int_ctor,
    .__dtor__ = (dtor_t)&int_dtor,
    .__str__ = (to_string_t)&int_str,
    .__add__ = (binary_operator_t)&int_add,
    .__sub__ = (binary_operator_t)&int_sub,
    .__mul__ = (binary_operator_t)&int_mul,
    .__div__ = (binary_operator_t)&int_div,
    .__eq__ = (binary_comparator_t)&int_eq,
    .__gt__ = (binary_comparator_t)&int_gt,
    .__lt__ = (binary_comparator_t)&int_lt},
    .i = 0};

const Class *Int = (const Class *)&_description;
