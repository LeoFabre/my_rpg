/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    char *buffer;
    int i;
    int power;

    power = 10;
    i = 0;
    while ((nb / power) > 0) {
        power = power * 10;
        i++;
    }
    if (!(buffer = calloc(10, sizeof(char))))
        return (NULL);
    power = i;
    buffer[i + 1] = '\0';
    while (i >= 0) {
        buffer[i] = (nb - ((nb / 10) * 10) + '0');
        i--;
        nb = nb / 10;
    }
    return (buffer);
}