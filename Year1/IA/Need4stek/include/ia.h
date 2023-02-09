/*
** EPITECH PROJECT, 2022
** B-AIA-200-REN-2-1-n4s-lucas.iglesia
** File description:
** ia
*/

#ifndef IA_H_
    #define IA_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #define UNUSED __attribute__((unused))

    void turn_wheels(float nb);
    void forward(float nb);
    void backward(float nb);
    int get_distance(void);
    int get_distance_left(void);
    int get_distance_right(void);
    int get_distance_far_left(void);
    int get_distance_far_right(void);
    void speed(void);
    void direction(void);

#endif /* !IA_H_ */
