/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void loop_rat(t_rpg *rpg, float rythm, t_mob *tmp)
{
    if (rythm >= 0.1) {
        tmp->rect.left += 64;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
        sfClock_restart(rpg->gameloop->moblist->clk_rat[SPRAT]);
    }
    if (tmp->rect.left >= 576) {
        tmp->rect.left = 0;
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
}

void animate_sprite_rat(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(
        rpg->gameloop->moblist->clk_rat[SPRAT]);
    float rythm = (float)time.microseconds / 1000000.0;
    t_mob *tmp = rpg->gameloop->moblist->first;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->id == RAT)
            loop_rat(rpg, rythm, tmp);
    }
}