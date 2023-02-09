/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct {
    Class   base;
    float x;
}   FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid pointer");
    this->x = (float)va_arg(*args, double);
}

static const char *float_str(FloatClass *this)
{
    static char buf[35];

    if (!this)
        raise("Invalid pointer");
    snprintf(buf, 35, "<Float (%f)>", this->x);
    return (strdup(buf));
}

static void float_dtor(FloatClass *this)
{
    (void)this;
}

static Object *float_add(const Object *this, const Object *obj)
{
    FloatClass *res = NULL;
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);
    float x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");

    x = my_this->x + my_obj->x;
    res = new(Float, x);
    return (res);
}

static Object *float_sub(const Object *this, const Object *obj)
{
    FloatClass *res = NULL;
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);
    float x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x - my_obj->x;
    res = new(Float, x);
    return (res);
}

static Object *float_mul(const Object *this, const Object *obj)
{
    FloatClass *res = NULL;
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);
    float x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x * my_obj->x;
    res = new(Float, x);
    return (res);
}

static Object *float_div(const Object *this, const Object *obj)
{
    FloatClass *res = NULL;
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);
    float x;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    if (my_obj->x == 0)
        raise("Division by zero");
    x = my_this->x / my_obj->x;
    res = new(Float, x);
    return (res);
}

static bool float_eq(const Object *this, const Object *obj)
{
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->x == my_obj->x);
}

static bool float_gt(const Object *this, const Object *obj)
{
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->x > my_obj->x);
}

static bool float_lt(const Object *this, const Object *obj)
{
    FloatClass *my_this = (FloatClass *)(this);
    FloatClass *my_obj = (FloatClass *)(obj);

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    return (my_this->x < my_obj->x);
}

// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_str,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;
