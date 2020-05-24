/*
** EPITECH PROJECT, 2019
** fptr
** File description:
** Leo Fabre
*/
#include "my.h"

void init_fptr(void (**fptr)())
{
    fptr[0] = (void *)&my_put_nbr;
    fptr[1] = (void *)&my_put_nbr;
    fptr[2] = (void *)&my_putstr;
    fptr[3] = (void *)&my_putchar;
    fptr[4] = &my_put_unsigned_nbr;
    fptr[5] = &my_hexa;
    fptr[6] = &my_capitalize_hexa;
    fptr[7] = &my_get_octal;
    fptr[8] = &my_binary;
    fptr[9] = &my_put_pointer_address;
    fptr[10] = &my_put_octal;
}