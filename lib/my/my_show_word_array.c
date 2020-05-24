/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/
#include "my.h"

void my_show_word_array(char **tab)
{
    for (int i = 0; tab[i]; ++i) {
        my_printf("(%s)\n", tab[i]);
    }
}