/*
** EPITECH PROJECT, 2019
** my_binary
** File description:
** Leo Fabre
*/
#include "my.h"

void my_binary(int nb)
{
    int res = 0;
    if (nb >= 2) {
        res = nb % 2;
        nb /= 2;
        my_binary(nb);
    } else if (nb > 0) {
        res = nb % 2;
        nb /= 2;
    }
    my_putchar(res + 48);
}

int my_get_binary(int nb)
{
    int res = 0;
    if (nb >= 2) {
        res = nb % 2;
        nb /= 2;
        my_get_binary(nb);
    } else if (nb > 0) {
        res = nb % 2;
        nb /= 2;
    }
    return (res);
}