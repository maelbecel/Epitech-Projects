/*
** EPITECH PROJECT, 2023
** algo
** File description:
** algo
*/

#ifndef ALGORYTHM_CPP_
#define ALGORYTHM_CPP_

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
T max(T a, T b)
{
    if (b < a)
        return (a);
    return (b);
}

template <typename T>
T clamp(T value, T min, T max)
{
    if (value < min)
        return (min);
    if (max < value)
        return (max);
    return (value);
}

#endif /* !ALGORYTHM_CPP_ */
