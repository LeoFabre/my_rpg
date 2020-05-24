/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void animate_particle(t_rpg *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->particles->attack->clk);
    float rythm = (float)time.microseconds / 1000000.0;

    if (rythm >= 0.01) {
        rpg->particles->attack->object->rect.left += 192;
        sfSprite_setTextureRect(rpg->particles->attack->object->sprite,
            rpg->particles->attack->object->rect);
        sfClock_restart(rpg->particles->attack->clk);
    }
    if (rpg->particles->attack->object->rect.left >= 5760) {
        rpg->particles->attack->object->rect.left = 0;
        rpg->particles->attack->is_rendered = FALSE;
    }
}

void display_attack_particle(t_rpg *rpg)
{
    if (rpg->particles->attack->is_rendered == TRUE) {
        animate_particle(rpg);
        sfRenderWindow_drawSprite(rpg->window,
            rpg->particles->attack->object->sprite, NULL);
    }
}

void spawn_attack_particle(t_rpg *rpg, sfSprite *on_sprite)
{
    sfIntRect particlerect = sfSprite_getTextureRect(
        rpg->particles->attack->object->sprite);
    sfIntRect spriterect = sfSprite_getTextureRect(on_sprite);
    sfVector2f spritepos = sfSprite_getPosition(on_sprite);
    float x = spritepos.x + ((float)spriterect.width / 2) -
        ((float)particlerect.width / 2);
    float y = spritepos.y + ((float)spriterect.height / 2) -
        ((float)particlerect.height / 2);

    sfSprite_setPosition(rpg->particles->attack->object->sprite,
        (sfVector2f){x, y});
    rpg->particles->attack->is_rendered = TRUE;
    display_attack_particle(rpg);
}