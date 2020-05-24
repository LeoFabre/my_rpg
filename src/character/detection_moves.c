/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

int color_pixel_detector(t_rpg *rpg, int x_char, int y_char)
{
    sfColor color;
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    int y = rpg->character->current_chunk[CHUNK_Y];
    int x = rpg->character->current_chunk[CHUNK_X];

    if (check_character_in_window(rpg) == 0) {
        color = sfImage_getPixel(rpg->character->moves[y][x],
            (unsigned)pos_char.x + x_char, (unsigned)pos_char.y + y_char);
        if (((color.b == 255 && color.r == 255 && color.g == 255) ||
            (color.r == 255 && color.b == 0 && color.g == 0) ||
            (color.r == 0 && color.b == 255 && color.g == 0) ||
            (color.r == 0 && color.b == 0 && color.g == 255) ||
            (color.r == 255 && color.b == 0 && color.g == 255))) {
            return (TRUE);
        }
    }
    return (FALSE);
}

int test_next_move(t_rpg *rpg)
{
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    sfVector2u win_size = sfRenderWindow_getSize(rpg->window);

    if (pos_char.x + SPEEDCHAR > (float)win_size.x ||
        pos_char.y + SPEEDCHAR > (float)win_size.y ||
        pos_char.x - SPEEDCHAR < 0 || pos_char.y - SPEEDCHAR < 0) {
        return (FALSE);
    }
    return (TRUE);
}