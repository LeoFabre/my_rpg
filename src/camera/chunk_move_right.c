/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void move_item_right(t_rpg *rpg)
{
    t_elem *tmp = rpg->gameloop->list_items->first;

    for (; tmp != NULL; tmp = tmp->next)
        sfSprite_move(tmp->object->sprite, (sfVector2f){-10.8, 0});
}

void loop_move_right(t_rpg *rpg)
{
    if (rpg->gameloop->bg_bf_char[0]->rect.left <=
        get_left_from_chunk_x(rpg) + HEIGHTMAP) {
        for (int i = 0; rpg->gameloop->bg_bf_char[i]; i++) {
            rpg->gameloop->bg_bf_char[i]->rect.left += 4;
            sfSprite_setTextureRect(rpg->gameloop->bg_bf_char[i]->sprite,
            rpg->gameloop->bg_bf_char[i]->rect);
        }
        rpg->gameloop->houses_up->rect.left += 4;
        sfSprite_setTextureRect(rpg->gameloop->houses_up->sprite,
            rpg->gameloop->houses_up->rect);
        sfSprite_move(rpg->character->obj->sprite, (sfVector2f){-10.8, 0});
        move_item_right(rpg);
    } else {
        rpg->character->current_chunk[CHUNK_X]++;
        rpg->gameloop->camera_mouv = CAMIDLE;
    }
}

void update_move_right(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gameloop->camera_clk);
    float rythm = (float)time.microseconds / 1000000.0;

    if (rpg->gameloop->camera_mouv == CAMRIGHT) {
        if (rythm >= CAMCLK) {
            loop_move_right(rpg);
            sfClock_restart(rpg->gameloop->camera_clk);
        }
    }
}

void move_chunk_right(t_rpg *rpg)
{
    sfColor color;
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    int y = rpg->character->current_chunk[CHUNK_Y];
    int x = rpg->character->current_chunk[CHUNK_X];

    if (check_character_in_window(rpg) == 0)
        color = sfImage_getPixel(rpg->character->moves[y][x],
        (unsigned)pos_char.x, (unsigned)pos_char.y);
    if (color.r == 0 && color.b == 255 && color.g == 0) {
        debug_print_moblist(rpg->gameloop->moblist);
        rpg->gameloop->camera_mouv = CAMRIGHT;
    }
}