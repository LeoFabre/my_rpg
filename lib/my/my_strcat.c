/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Leo Fabre
*/
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *a, char *b)
{
    int len = my_strlen(a) + my_strlen(b);
    int i = 0;
    char *res = malloc(sizeof(char) * (len + 1));

    for (; i < my_strlen(a); ++i)
        res[i] = a[i];
    i = 0;
    for (int j = my_strlen(a); i < my_strlen(b); ++j, ++i)
        res[j] = b[i];
    res[len] = '\0';
    return res;
}