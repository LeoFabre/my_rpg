/*
** EPITECH PROJECT, 2024
** MUL_my_defender_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

int cur_on_hitbox(t_rpg *mydefender, sfSprite *sprite)
{
    sfIntRect sprite_rect;
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(mydefender->window);

    sprite_rect.top = sfSprite_getTextureRect(sprite).top;
    sprite_rect.left = sfSprite_getTextureRect(sprite).left;
    sprite_rect.height = sfSprite_getTextureRect(sprite).height;
    sprite_rect.width = sfSprite_getTextureRect(sprite).width;
    if (sfSprite_getPosition(sprite).x < (float)mousepos.x &&
        (float)mousepos.x <
            sfSprite_getPosition(sprite).x + (float)sprite_rect.width &&
        sfSprite_getPosition(sprite).y < (float)mousepos.y &&
        (float)mousepos.y <
            sfSprite_getPosition(sprite).y + (float)sprite_rect.height) {
        return (1);
    } else
        return (0);
}