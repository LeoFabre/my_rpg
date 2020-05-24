/*
** EPITECH PROJECT, 2019
** my_put_unsigned_nb
** File description:
** Leo Fabre
*/
#include "my.h"

void my_put_unsigned_nbr(unsigned int nb)
{
    unsigned int temp;

    if (nb >= 10) {
        temp = nb % 10;
        nb = nb / 10;
        my_put_unsigned_nbr(nb);
        my_putchar(temp + 48);
    } else
        my_putchar(nb + 48);
}