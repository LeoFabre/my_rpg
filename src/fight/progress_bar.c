/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/
#include "rpg.h"

void draw_progress_bar(t_rpg *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->fight->progressbar->spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->fight->progress->spr, NULL);
}

void update_progression(t_rpg *rpg)
{
    static int width = 0;
    sfIntRect progressrect = {.left = 0, .height = 99, .top = 0, .width = 0};
    sfTime time = sfClock_getElapsedTime(rpg->fight->clk);
    float rythm = (float)time.microseconds / 1000000.0;
    static int way = CURVEUP;

    if (rythm <= 1.30) {
        if (width >= 781)
            way = CURVEDOWN;
        if (width <= 0)
            way = CURVEUP;
        if (way == CURVEUP)
            width += 10 * 1.3f * rpg->character->level;
        else
            width -= 10 * 1.3f * rpg->character->level;
        progressrect.width = width;
        sfSprite_setTextureRect(rpg->fight->progress->spr, progressrect);
    }
    if (rythm > 1.30)
        sfClock_restart(rpg->fight->clk);
}