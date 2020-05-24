/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void init_character_details(t_rpg *rpg)
{
    sfFont *font = sfFont_createFromFile("ressources/fonts/new_itemfont.ttf");
    rpg->hud->pnj_details = malloc(sizeof(sfText *) * 4);
    rpg->hud->pnj_details[TEXT_XP] = create_text("+0 EXP\n", font, sfBlue, 35);
    rpg->hud->pnj_details[TEXT_PPV] = create_text("+0\n", font, sfRed, 35);
    rpg->hud->pnj_details[TEXT_MPV] = create_text("-0\n", font, sfRed, 35);
    rpg->hud->pnj_details[3] = create_text("-0\n", font, sfRed, 35);
    rpg->hud->details = 0;
    rpg->hud->details_mob_pv = 0;
    rpg->hud->details_pv = 0;
    rpg->hud->clock = malloc(sizeof(sfClock *) * 4);
    rpg->hud->clock[0] = sfClock_create();
    rpg->hud->clock[1] = sfClock_create();
    rpg->hud->clock[2] = sfClock_create();
    rpg->hud->clock[3] = sfClock_create();
}

void init_hud(t_rpg *rpg)
{
    int x;

    rpg->hud = malloc(sizeof(t_hud));
    rpg->hud->xp_sound = create_sound("ressources/sounds/orb.ogg");
    sfSound_setVolume(rpg->hud->xp_sound, 50);
    rpg->hud->xp_bar = malloc(sizeof(sfSprite *) * 2);
    rpg->hud->xp_bar[0] = create_sprite("ressources/hud/xpbar_empty.png");
    rpg->hud->xp_bar[1] = create_sprite("ressources/hud/xpbar_full.png");
    sfSprite_setScale(rpg->hud->xp_bar[0], (sfVector2f){0.9, 1});
    sfSprite_setScale(rpg->hud->xp_bar[1], (sfVector2f){0.9, 1});
    update_xp(rpg);
    rpg->hud->bar_sprite = create_sprite("ressources/hud/hud.png");
    sfSprite_setScale(rpg->hud->bar_sprite, (sfVector2f){1, 0.75});
    rpg->hud->heart_sprite = malloc(sizeof(sfSprite *) * 21);
    for (x = 0; x <= 19; x++) {
        rpg->hud->heart_sprite[x] = create_sprite("ressources/hud/heart.png");
        sfSprite_setScale(rpg->hud->heart_sprite[x],
            (sfVector2f){0.027, 0.027});
    }
    rpg->hud->heart_sprite[x] = NULL;
    init_character_details(rpg);
}

void draw_xp(t_rpg *rpg)
{
    drawer(rpg->window, rpg->hud->xp_bar[0], 5, 75);
    drawer(rpg->window, rpg->hud->xp_bar[1], 5, 75);
    draw_text_levitate(rpg, rpg->hud->pnj_details[TEXT_XP], &rpg->hud->details,
        rpg->hud->clock[0]);
}

void display_hud(t_rpg *rpg)
{
    int x_to_add = 0;
    int x = 0;

    drawer(rpg->window, rpg->hud->bar_sprite, 0, 2);
    for (int cpt = 0; cpt < (rpg->character->health - 5); x++) {
        if (x <= 9) {
            drawer(rpg->window, rpg->hud->heart_sprite[x], 35 + x_to_add, 20);
            if (x == 9) {
                x_to_add = 0;
                continue;
            }
        } else
            drawer(rpg->window, rpg->hud->heart_sprite[x], 35 + x_to_add, 50);
        x_to_add += 28;
        cpt += 5;
    }
    draw_xp(rpg);
}