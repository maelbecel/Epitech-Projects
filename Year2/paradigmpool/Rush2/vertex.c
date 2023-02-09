/*
** EPITECH PROJECT, 2023
** B-PDG-300-REN-3-1-PDGRUSH2-lucas.iglesia
** File description:
** vertex
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x, y, z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid pointer");
    int x = va_arg(*args, int);
    int y = va_arg(*args, int);
    int z = va_arg(*args, int);

    this->x = x;
    this->y = y;
    this->z = z;

}

static void vertex_dtor(VertexClass *this)
{
    (void)this;
}

// Create additional functions here
static char *vertex_str(VertexClass *this)
{
    char buffer[47];

    if (!this)
        raise("Invalid pointer");
    snprintf(buffer, 47, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return strdup(buffer);
}

static Object *vertex_add(const Object *this, const Object *other)
{
    VertexClass *my_this = (VertexClass *)(this);
    VertexClass *my_other = (VertexClass *)(other);
    int x;
    int y;
    int z;

    if (!my_this || !my_other)
        raise("Invalid pointer");
    x = my_this->x + my_other->x;
    y = my_this->y + my_other->y;
    z = my_this->z + my_other->z;
    return (VertexClass *)(new(Vertex, x, y, z));
}

static Object *vertex_sub(const Object *this, const Object *other)
{
    VertexClass *my_this = (VertexClass *)(this);
    VertexClass *my_other = (VertexClass *)(other);
    int x;
    int y;
    int z;

    if (!my_this || !my_other)
        raise("Invalid pointer");
    x = my_this->x - my_other->x;
    y = my_this->y - my_other->y;
    z = my_this->z - my_other->z;
    return (VertexClass *)(new (Vertex, x, y, z));
}

static const VertexClass _description = {
    {/* Class struct */
    .__size__ = sizeof(VertexClass),
    .__name__ = "Vertex",
    .__ctor__ = (ctor_t)&vertex_ctor,
    .__dtor__ = (dtor_t)&vertex_dtor,
    .__str__ = (to_string_t)&vertex_str,
    .__add__ = (binary_operator_t)&vertex_add,
    .__sub__ = (binary_operator_t)&vertex_sub,
    .__mul__ = NULL,
    .__div__ = NULL,
    .__eq__ = NULL,
    .__gt__ = NULL,
    .__lt__ = NULL},
    .x = 0,
    .y = 0};

const Class *Vertex = (const Class *)&_description;
