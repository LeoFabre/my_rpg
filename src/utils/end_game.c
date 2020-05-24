/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void end_game(t_rpg *rpg)
{
    rpg->menu->gameoverlogo = make_obj("ressources/mainmenu/endlogo.png");
    init_logo_pos(rpg, rpg->menu->gameoverlogo);
    rpg->gamestate = GAMEOVERLOOP;
}