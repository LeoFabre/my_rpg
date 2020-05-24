/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

t_game_item *create_dropped_item(char *path_sp, sfVector2f pos, sfIntRect rect,
    int id)
{
    t_game_item *object = malloc(sizeof(t_game_item));

    object->texture = sfTexture_createFromFile(path_sp, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setPosition(object->sprite, pos);
    sfSprite_setTextureRect(object->sprite, rect);
    object->rect = rect;
    object->pos = pos;
    object->id = id;
    return (object);
}