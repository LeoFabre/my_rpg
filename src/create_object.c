/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/
#include "rpg.h"
#include "stdlib.h"

void destroy_obj(t_obj *obj)
{
    sfSprite_destroy(obj->spr);
    sfTexture_destroy(obj->tex);
    free(obj);
}

t_obj *make_obj(const char *filepath)
{
    t_obj *res = malloc(sizeof(t_obj));

    res->spr = sfSprite_create();
    res->tex = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(res->spr, res->tex, sfFalse);
    return res;
}

t_game_object *create_object(const char *path_sp, sfVector2f pos,
    sfIntRect rect)
{
    t_game_object *object = malloc(sizeof(t_game_object));

    my_printf("creating object from (%s)\n", path_sp);
    object->texture = sfTexture_createFromFile(path_sp, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setPosition(object->sprite, pos);
    sfSprite_setTextureRect(object->sprite, rect);
    object->rect = rect;
    object->pos = pos;
    return (object);
}