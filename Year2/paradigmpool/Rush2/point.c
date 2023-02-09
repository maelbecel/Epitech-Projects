/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class   base;
    int     x;
    int     y;
}   PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid pointer");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static const char *point_str(PointClass *this)
{
    static char buf[33];

    if (!this)
        raise("Invalid pointer");
    snprintf(buf, 33, "<Point (%d, %d)>", this->x, this->y);
    return (strdup(buf));
}

static void point_dtor(PointClass *this)
{
    (void)this;
}

static Object *point_add(const Object *this, const Object *obj)
{
    PointClass *res = NULL;
    PointClass *my_this = (PointClass *)(this);
    PointClass *my_obj = (PointClass *)(obj);
    int x;
    int y;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x + my_obj->x;
    y = my_this->y + my_obj->y;
    res = new(Point, x, y);
    return (res);
}

static Object *point_sub(const Object *this, const Object *obj)
{
    PointClass *res = NULL;
    PointClass *my_this = (PointClass *)(this);
    PointClass *my_obj = (PointClass *)(obj);
    int x;
    int y;

    if (!(my_this) || !(my_obj))
        raise("Invalid pointer");
    x = my_this->x - my_obj->x;
    y = my_this->y - my_obj->y;
    res = new(Point, x, y);
    return (res);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_str,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
