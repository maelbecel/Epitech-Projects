/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** x
*/
void    my_sort_int_array(int *array, int size)
{
    int i = 0;
    int temp;

    while (i < size - 1) {
        if (array[i + 1] < array[i]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = 0;
        }
        else {
            i = i + 1;
        }
    }
}
