/*
** EPITECH PROJECT, 2024
** day04
** File description:
** Created by Leo Fabre
*/
#include "my.h"

int my_putstr(char const *str)
{
    if (str == 0) {
        my_putstr("(null)");
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}