/*
** EPITECH PROJECT, 2019
** my_put_pointer_address
** File description:
** Leo Fabre
*/
#include "my.h"

void my_put_pointer_address(unsigned int nb)
{
    my_putstr("0x");
    my_hexa(nb);
}