/*
** EPITECH PROJECT, 2021
** print_action.c
** File description:
** print action
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "architect.h"

float **translation(char * element_one, char * element_two)
{
    float **identity = create_identity();
    vector_t vector_translation;
    vector_translation.x = atof(element_one);
    vector_translation.y = atof(element_two);
    printf("Translation along vector (%s, %s)\n", element_one, element_two);
    matrix_translation(identity, &vector_translation);
    return identity;
}

float **scaling(char * element_one, char * element_two)
{
    float **identity = create_identity();
    vector_t vector_scaling;
    vector_scaling.x = atof(element_one);
    vector_scaling.y = atof(element_two);
    printf("Scaling by factors %s and %s\n", element_one, element_two);
    matrix_scaling(identity, &vector_scaling);
    return identity;
}

float **rotation(char * element)
{
    float **identity = create_identity();
    angle_t angle_rotation;
    angle_rotation.x1 = cos(atof(element) * M_PI / 180);
    angle_rotation.x2 = sin(atof(element) * -1 * M_PI / 180);
    angle_rotation.y1 = sin(atof(element) * M_PI / 180);
    angle_rotation.y2 = cos(atof(element) * M_PI / 180);
    if (angle_rotation.x2 < 0 && angle_rotation.x2 > 0.01)
        angle_rotation.x2 = angle_rotation.x2 * -1;
    printf("Rotation by a %s angle\n", element);
    matrix_rotation(identity, &angle_rotation);
    return identity;
}

float **reflexion(char *element)
{
    float **identity = create_identity();
    angle_t angle_reflection;
    angle_reflection.x1 = cos(atof(element) * 2 * M_PI / 180);
    angle_reflection.x2 = sin(atof(element) * 2 * M_PI / 180);
    angle_reflection.y1 = sin(atof(element) * 2 * M_PI / 180);
    angle_reflection.y2 = cos(atof(element) * 2 * M_PI / 180);
    angle_reflection.y2 *= -1;
    printf("Reflection over an axis with an inclination angle of %s degrees\n", element);
    matrix_reflection(identity, &angle_reflection);
    return identity;
}

float **print_action(int nbarg, char **elements, float **identity)
{
    for (int i = nbarg - 1; i > 0 ; i--){
        if ((elements[i][0] == '-') && (elements[i][1] == 't')){
            identity = product_matrix(identity, translation(elements[i+1], elements[i+2]));
            i-=2;
        }
        else if ((elements[i][0] == '-') && (elements[i][1] == 'z')){
            identity = product_matrix(identity, scaling(elements[i+1], elements[i+2]));
            i-=2;
        }
        else if ((elements[i][0] == '-') && (elements[i][1] == 'r')){
            identity = product_matrix(identity, rotation(elements[i+1]));
            i--;
        }
        else if ((elements[i][0] == '-') && (elements[i][1] == 's')){
            identity = product_matrix(identity, reflexion(elements[i + 1]));
            i--;
        }
    }
    return identity;
}
