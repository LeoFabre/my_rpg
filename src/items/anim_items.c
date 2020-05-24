/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void anim_items(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gameloop->anim_items);
    float rythm = (float)time.microseconds / 1000000.0;
    t_elem *tmp = rpg->gameloop->list_items->first;

    if (rythm <= 0.3) {
        for (; tmp != NULL; tmp = tmp->next)
            sfSprite_move(tmp->object->sprite, (sfVector2f){0, -0.5});
    }
    tmp = rpg->gameloop->list_items->first;
    if (rythm >= 0.3) {
        for (; tmp != NULL; tmp = tmp->next)
            sfSprite_move(tmp->object->sprite, (sfVector2f){0, +0.45});
    }
    if (rythm >= 0.6)
        sfClock_restart(rpg->gameloop->anim_items);
}