/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void move_item_down(t_rpg *rpg)
{
    t_elem *tmp = rpg->gameloop->list_items->first;

    for (; tmp != NULL; tmp = tmp->next)
        sfSprite_move(tmp->object->sprite, (sfVector2f){0, -10.8});
}

void loop_move_down(t_rpg *rpg)
{
    if (rpg->gameloop->bg_bf_char[0]->rect.top <=
        get_top_from_chunk_y(rpg) + WIDTHMAP) {
        for (int i = 0; rpg->gameloop->bg_bf_char[i]; i++) {
            rpg->gameloop->bg_bf_char[i]->rect.top += 4;
            sfSprite_setTextureRect(rpg->gameloop->bg_bf_char[i]->sprite,
            rpg->gameloop->bg_bf_char[i]->rect);
        }
        rpg->gameloop->houses_up->rect.top += 4;
        sfSprite_setTextureRect(rpg->gameloop->houses_up->sprite,
            rpg->gameloop->houses_up->rect);
        rpg->gameloop->fence->rect.top += 4;
        sfSprite_setTextureRect(rpg->gameloop->fence->sprite,
            rpg->gameloop->fence->rect);
        sfSprite_move(rpg->character->obj->sprite, (sfVector2f){0, -8.8});
        move_item_down(rpg);
    } else {
        rpg->character->current_chunk[CHUNK_Y]++;
        rpg->gameloop->camera_mouv = CAMIDLE;
    }
}

void update_move_down(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gameloop->camera_clk);
    float rythm = (float)time.microseconds / 1000000.0;

    if (rpg->gameloop->camera_mouv == CAMDOWN) {
        if (rythm >= CAMCLK) {
            loop_move_down(rpg);
            sfClock_restart(rpg->gameloop->camera_clk);
        }
    }
}

void move_chunk_down(t_rpg *rpg)
{
    sfColor color;
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    int y = rpg->character->current_chunk[CHUNK_Y];
    int x = rpg->character->current_chunk[CHUNK_X];

    if (check_character_in_window(rpg) == 0)
        color = sfImage_getPixel(rpg->character->moves[y][x],
        (unsigned)pos_char.x, (unsigned)pos_char.y);
    if (color.r == 255 && color.b == 0 && color.g == 255) {
        rpg->gameloop->camera_mouv = CAMDOWN;
    }
}