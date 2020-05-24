/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void init_hud_pause(t_rpg *rpg)
{
    rpg->hud->pause = 0;
    rpg->hud->p_is_pressed = 0;
}