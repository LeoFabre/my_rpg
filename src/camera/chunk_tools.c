/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

int get_top_from_chunk_y(t_rpg *rpg)
{
    return 96 + (rpg->character->current_chunk[CHUNK_Y] * WIDTHMAP);
}

int get_left_from_chunk_x(t_rpg *rpg)
{
    return rpg->character->current_chunk[CHUNK_X] * HEIGHTMAP;
}