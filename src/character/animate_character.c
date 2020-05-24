/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void animate_character(t_rpg *rpg, int dir)
{
    sfTime time;
    float rythm;
    sfVector2u size = sfTexture_getSize(rpg->character->obj->texture);
    int height_char = (int)size.y / 4;
    int width_char = (int)size.x / 4;

    if (dir == -1) {
        rpg->character->obj->rect.top = 0;
        rpg->character->obj->rect.left = width_char;
        return;
    }
    time = sfClock_getElapsedTime(rpg->character->clkanim);
    rythm = (float)time.microseconds / 1000000.0;
    if (rythm >= 0.15) {
        if (rpg->character->obj->rect.left >= (int)size.x - width_char)
            rpg->character->obj->rect.left = 0;
        rpg->character->obj->rect.top = height_char * dir;
        rpg->character->obj->rect.left += width_char;
        sfClock_restart(rpg->character->clkanim);
    }
}