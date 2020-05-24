/*
** EPITECH PROJECT, 2019
** my_put_octal
** File description:
** Leo Fabre
*/
#include "my.h"

void my_put_octal(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putstr("\\");
            my_get_octal(str[i]);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
}