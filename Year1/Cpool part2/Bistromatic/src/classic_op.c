/*
** EPITECH PROJECT, 2021
** classic_op.c
** File description:
** Classic operation
*/

int classic_op(int a, int b, char op)
{
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '%': return a % b;
        case '*': return a * b;
    }
    return 0;
}
