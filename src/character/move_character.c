/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

int check_character_in_window(t_rpg *rpg)
{
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    sfVector2u window_size = sfWindow_getSize((sfWindow const *)rpg->window);
    if (pos_char.x > (float)window_size.x ||
        pos_char.y > (float)window_size.y || pos_char.x < 0 || pos_char.y < 0) {
        return (1);
    }
    return (0);
}

void move_down(t_rpg *rpg)
{
    if (rpg->audio->run == 0) {
        rpg->audio->update = 1;
        rpg->audio->run = 1;
    } else {
        rpg->audio->update = 0;
    }
    if (color_pixel_detector(rpg, 0, 60) == TRUE &&
        test_next_move(rpg) == TRUE && rpg->gameloop->camera_mouv == 0) {
        sfSprite_move(rpg->character->obj->sprite, (sfVector2f){0, SPEEDCHAR});
    }
}

void move_up(t_rpg *rpg)
{
    if (rpg->audio->run == 0) {
        rpg->audio->update = 1;
        rpg->audio->run = 1;
    } else
        rpg->audio->update = 0;
    if (color_pixel_detector(rpg, 0, 0) == TRUE &&
        test_next_move(rpg) == TRUE && rpg->gameloop->camera_mouv == 0)
        sfSprite_move(rpg->character->obj->sprite, (sfVector2f){0, -SPEEDCHAR});
}

void move_right(t_rpg *rpg)
{
    if (rpg->audio->run == 0) {
        rpg->audio->update = 1;
        rpg->audio->run = 1;
    } else
        rpg->audio->update = 0;
    if (color_pixel_detector(rpg, 40, 0) == TRUE &&
        test_next_move(rpg) == TRUE && rpg->gameloop->camera_mouv == 0)
        sfSprite_move(rpg->character->obj->sprite, (sfVector2f){SPEEDCHAR, 0});
}

void move_left(t_rpg *rpg)
{
    if (rpg->audio->run == 0) {
        rpg->audio->update = 1;
        rpg->audio->run = 1;
    } else
        rpg->audio->update = 0;
    if (color_pixel_detector(rpg, -10, 0) == TRUE &&
        test_next_move(rpg) == TRUE && rpg->gameloop->camera_mouv == 0)
        sfSprite_move(rpg->character->obj->sprite, (sfVector2f){-SPEEDCHAR, 0});
}