/*
** EPITECH PROJECT, 2019
** my_hexa
** File description:
** Leo Fabre
*/
#include "my.h"

void my_hexa(int nb)
{
    int res = 0;

    if (nb >= 16) {
        res = nb % 16;
        nb /= 16;
        my_hexa(nb);
    } else if (nb > 0) {
        res = nb % 16;
        nb /= 16;
    }
    if (res > 9)
        my_putchar(res + 'a' - 10);
    else
        my_putchar(res + '0');
}