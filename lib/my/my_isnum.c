/*
** EPITECH PROJECT, 2024
** my_isnum
** File description:
** returns 1 if c is a number
*/

int my_isnum(char const c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}