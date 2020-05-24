/*
** EPITECH PROJECT, 2024
** MUL_my_defender_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

sfText *create_text(const char *text, sfFont *font, sfColor color, int height)
{
    sfText *result = sfText_create();

    sfText_setCharacterSize(result, height);
    sfText_setString(result, text);
    sfText_setFont(result, font);
    sfText_setColor(result, color);
    return (result);
}

void draw_text_levitate(t_rpg *rpg, sfText *text, int *details, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float rythm = (float)time.microseconds / 1000000.0;
    static int to_add = 0;
    sfColor my_color = sfText_getColor(text);
    sfVector2f pos = sfSprite_getPosition(rpg->character->obj->sprite);

    if ((*details) > 0) {
        if (my_color.a <= 10)
            (*details) = 0;
        draw_text(rpg->window, text, (int)pos.x,
            ((int)pos.y - 35) - (to_add * 3));
        if (rythm > 0.02) {
            my_color.a -= 10;
            sfText_setColor(text, my_color);
            sfClock_restart(clock);
            to_add++;
            (*details)--;
        }
    } else
        to_add = 0;
}

void draw_text_levitate_mob(t_rpg *rpg, sfText *text, int *details,
    sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float rythm = (float)time.microseconds / 1000000.0;
    static int to_add = 0;
    sfColor my_color = sfText_getColor(text);
    sfVector2f pos = sfSprite_getPosition(rpg->fight->opponent->sprite);

    if ((*details) > 0) {
        if (my_color.a <= 10)
            (*details) = 0;
        draw_text(rpg->window, text, (int)pos.x,
            ((int)pos.y - 35) - (to_add * 3));
        if (rythm > 0.02) {
            my_color.a -= 10;
            sfText_setColor(text, my_color);
            sfClock_restart(clock);
            to_add++;
            (*details)--;
        }
    } else
        to_add = 0;
}