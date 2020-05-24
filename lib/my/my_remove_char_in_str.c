/*
** EPITECH PROJECT, 2024
** calc
** File description:
** Created by Leo Fabre
*/

#include "my.h"
#include <stdlib.h>

int my_count_char_in_str(char c, char *str)
{
    int res = 0;

    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] == c)
            res++;
    }
    return res;
}

char *remove_c_in_str(char *str, char c)
{
    char *new_str = malloc(
        sizeof(char) * (my_strlen(str) - my_count_char_in_str(c, str) + 1));
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c) {
            new_str[cnt] = str[i];
            cnt++;
        }
    }
    new_str[cnt + 1] = '\0';
    return (new_str);
}

char *remove_chars_in_str(char *rm, char *str)
{
    char *res = NULL;

    for (int i = 0; i < my_strlen(rm); ++i)
        res = remove_c_in_str(str, rm[i]);
    return res;
}