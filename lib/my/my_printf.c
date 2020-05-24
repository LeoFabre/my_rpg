/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Leo Fabre
*/

#include <stdarg.h>
#include "my.h"

int print_char_or_flag(char const *str, void (**fptr)(), va_list ap, int i)
{
    if (str[i] == '%' && str[i + 1] == '%') {
        i++;
        my_putchar(str[i]);
    } else if (str[i] == '%') {
        i++;
        for (; str[i] == ' '; ++i);
        if (check_flags(str[i]) != 666) {
            (str[i - 1] == ' ') ? my_putchar(' ') : 1;
            fptr[(check_flags(str[i]))](va_arg(ap, void *));
        } else {
            my_putstr("%");
            (str[i - 1] == ' ') ? my_putchar(' ') : 1;
            my_putchar(str[i]);
        }
    } else
        my_putchar(str[i]);
    return i;
}

void print_loop(char const *str, void (**fptr)(), va_list ap)
{
    for (int i = 0; str[i]; i++)
        i = print_char_or_flag(str, fptr, ap, i);
}

void my_printf(char *str, ...)
{
    void (*fptr[11])();
    va_list ap;

    va_start(ap, str);
    init_fptr(fptr);
    print_loop(str, fptr, ap);
    va_end(ap);
}
