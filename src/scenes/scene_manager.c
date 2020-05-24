/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void scene_manager(t_rpg *rpg, void ((*array[5])(t_rpg *)))
{
    (array[rpg->gamestate])(rpg);
}