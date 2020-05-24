/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void create_background(t_rpg *rpg)
{
    rpg->gameloop->bg_bf_char = malloc(sizeof(t_game_object) * 3);
    rpg->gameloop->bg_bf_char[0] = create_object("ressources/map/back.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 608, 512, 256});
    rpg->gameloop->bg_bf_char[1] = create_object("ressources/map/houses.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 608, 512, 256});
    rpg->gameloop->bg_bf_char[2] = NULL;
    rpg->gameloop->houses_up = create_object("ressources/map/houses_up.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 608, 512, 256});
    rpg->gameloop->fence = create_object("ressources/map/my_rpg_obstacles.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 608, 512, 256});
    sfSprite_setScale(rpg->gameloop->bg_bf_char[0]->sprite, (sfVector2f){3, 3});
    sfSprite_setScale(rpg->gameloop->bg_bf_char[1]->sprite, (sfVector2f){3, 3});
    sfSprite_setScale(rpg->gameloop->houses_up->sprite, (sfVector2f){3, 3});
    sfSprite_setScale(rpg->gameloop->fence->sprite, (sfVector2f){3, 3});
}