/*
** EPITECH PROJECT, 2019
** my_octal
** File description:
** Leo Fabre
*/
#include "my.h"

void my_get_octal(int nb)
{
    int tab[3] = {0, 0, 0};
    int i = 2;
    int res = 0;

    if (nb == 0) {
        my_put_nbr(0);
        return;
    }
    while (nb > 0) {
        res = nb % 8;
        nb /= 8;
        tab[i] = res;
        i--;
    }
    my_put_nbr(tab[0]);
    my_put_nbr(tab[1]);
    my_put_nbr(tab[2]);
}

void my_octal(int number)
{
    if (number == 0)
        my_put_nbr(0);
    else
        my_put_nbr(number % 8 + 10 * my_get_binary(number / 8));
}