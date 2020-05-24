/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int len;
    char *dup;

    len = my_strlen(str) + 1;
    dup = malloc(len);
    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}