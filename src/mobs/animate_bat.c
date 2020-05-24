/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void animate_sprite_bat(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(
        rpg->gameloop->moblist->clk_bat[SPBAT]);
    float rythm = (float)time.microseconds / 1000000.0;
    t_mob *tmp = rpg->gameloop->moblist->first;

    if (tmp->id == BAT) {
        if (rythm >= 0.1) {
            tmp->rect.left += 16;
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
            sfClock_restart(rpg->gameloop->moblist->clk_bat[SPBAT]);
        }
        if (tmp->rect.left >= 80) {
            tmp->rect.left = 0;
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
        }
    }
}

void animate_bat(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(
        rpg->gameloop->moblist->clk_bat[ANIMBAT]);
    float rythm = (float)time.microseconds / 1000000.0;
    t_mob *tmp = rpg->gameloop->moblist->first;

    if (rythm <= 0.3) {
        for (; tmp != NULL; tmp = tmp->next)
            if (tmp->id == BAT)
                sfSprite_move(tmp->sprite, (sfVector2f){0, -0.7});
    }
    tmp = rpg->gameloop->moblist->first;
    if (rythm >= 0.3) {
        for (; tmp != NULL; tmp = tmp->next)
            if (tmp->id == BAT)
                sfSprite_move(tmp->sprite, (sfVector2f){0, +0.65});
    }
    if (rythm >= 0.6)
        sfClock_restart(rpg->gameloop->moblist->clk_bat[ANIMBAT]);
}