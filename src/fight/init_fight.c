/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void init_fight(t_rpg *rpg)
{
    rpg->fight = malloc(sizeof(t_fight));
    rpg->fight->progressbar = make_obj("ressources/fight/progressbar_bg.png");
    rpg->fight->progress = make_obj("ressources/fight/progress.png");
    center_obj_yoffset(rpg, rpg->fight->progressbar, 1.3f);
    center_obj_yoffset(rpg, rpg->fight->progress, 1.3f);
    rpg->fight->pressing_atk = FALSE;
    rpg->fight->is_player_turn = TRUE;
    rpg->fight->opponent = NULL;
    rpg->fight->clk = sfClock_create();
}