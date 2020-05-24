/*
** EPITECH PROJECT, 2019
** check_flags
** File description:
** Leo Fabre
*/

int check_flags(char c)
{
    char *flags = "discuxXobpS";

    for (int i = 0; flags[i]; ++i)
        if (c == flags[i])
            return (i);
    return (666);
}