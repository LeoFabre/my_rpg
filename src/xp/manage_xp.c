/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void update_xp(t_rpg *rpg)
{
    sfIntRect progressrect = {.left = 0, .height = 10, .top = 0,
        .width = rpg->character->xp};

    if (rpg->character->xp >= 360) {
        rpg->character->xp -= 360;
        rpg->character->level++;
    }
    sfSprite_setTextureRect(rpg->hud->xp_bar[1], progressrect);
}

void add_xp(t_rpg *rpg, int xp)
{
    char *res = malloc(sizeof(char) * 3);

    res[0] = '+';
    res[1] = ' ';
    res[2] = '\0';
    res = my_strcat(res, my_itoa(xp));
    res = my_strcat(res, " XP");
    sfText_setString(rpg->hud->pnj_details[0], res);
    free(res);
    rpg->hud->details = 70;
    sfSound_play(rpg->hud->xp_sound);
    rpg->character->xp += xp;
    update_xp(rpg);
}