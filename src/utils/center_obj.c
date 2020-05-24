/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

float get_center_y(t_rpg *rpg, t_obj *obj, float div_offset)
{
    float winy = (float)sfWindow_getSize((const sfWindow *)rpg->window).y;

    if (div_offset == 0)
        return (winy / 2.f) - (sfSprite_getLocalBounds(obj->spr).height / 2);
    else
        return (winy / div_offset) -
            (sfSprite_getLocalBounds(obj->spr).height / 2);
}

float get_center_x(t_rpg *rpg, t_obj *obj)
{
    float winx = (float)sfWindow_getSize((const sfWindow *)rpg->window).x;

    return ((winx / 2) - (sfSprite_getLocalBounds(obj->spr).width / 2));
}

void center_obj(t_rpg *rpg, t_obj *obj)
{
    sfVector2f pos = {get_center_x(rpg, obj), get_center_y(rpg, obj, 0)};

    sfSprite_setPosition(obj->spr, pos);
}

void center_obj_yoffset(t_rpg *rpg, t_obj *obj, float y_offset)
{
    sfVector2f pos = {get_center_x(rpg, obj), get_center_y(rpg, obj, y_offset)};

    sfSprite_setPosition(obj->spr, pos);
}