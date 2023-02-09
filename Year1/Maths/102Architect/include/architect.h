/*
** EPITECH PROJECT, 2021
** architect.H
** File description:
** archi
*/

#ifndef ARCHI
#define ARCHI


typedef struct vector
{
    float x;
    float y;
}vector_t;

typedef struct angle
{
    float x1;
    float x2;
    float y1;
    float y2;
} angle_t;

typedef struct action
{
    char *type;
    float i;
    float j;
}action_t;

float **print_action(int nbarg, char **elements, float **identity);
float **create_identity(void);
float **create_matrix(int x, int y);
float **matrix_translation(float **matrix, vector_t *vector);
float **matrix_scaling(float **matrix, vector_t *vector);
float **matrix_rotation(float **matrix, angle_t *angle);
float **matrix_reflection(float **matrix, angle_t *angle);
float **product_matrix (float **matrix_one, float **matrix_two);
float **create_matrice_3x1(char *arg1, char *arg2);
float **product_matrix_3x1(float **matrix_one, float **matrix_two);

#endif
