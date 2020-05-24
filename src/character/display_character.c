/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void display_character(t_rpg *rpg)
{
    sfSprite_setTextureRect(rpg->character->obj->sprite,
        rpg->character->obj->rect);
    if (rpg->gameloop->camera_mouv == 0) {
        sfRenderWindow_drawSprite(rpg->window, rpg->character->obj->sprite,
            NULL);
    }
}