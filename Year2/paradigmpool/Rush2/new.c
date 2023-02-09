/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH2-lucas.iglesia
** File description:
** new
*/

#include "new.h"
#include "player.h"
#include "raise.h"
#include "object.h"

Object *new(const Class *class, ...)
{
    Object *newclass;
    va_list ap;

    if (!class)
        raise("class is null");
    va_start(ap, class);
    newclass = va_new(class, &ap);
    va_end(ap);
    return newclass;
}

Object *va_new (const Class *class, va_list *ap)
{
    Object *newclass;

    newclass = malloc(class->__size__);
    if (!newclass)
        raise("can't allocate memory");
    memcpy(newclass, class, class->__size__);
    if (((Class *)newclass)->__ctor__)
        ((Class *)newclass)->__ctor__(newclass, ap);
    return newclass;
}

void delete(Object *ptr)
{
    Class *class = ptr;

    if (!class)
        raise("class is null");
    if (class->__dtor__)
        class->__dtor__(class);
    free(class);
}
