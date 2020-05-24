/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_npc_dialog
*/

#include "rpg.h"

void display_npc_dialog(t_rpg *rpg)
{
    if (rpg->npc_manager->is_in_dialog) {
        sfSprite_setScale(rpg->npc_manager->dialog_sprite,
            (sfVector2f){6.0, 6.0});
        drawer(rpg->window, rpg->npc_manager->dialog_sprite,
            (int)(sfRenderWindow_getSize(rpg->window).x) / 2 - 350,
            (int)(sfRenderWindow_getSize(rpg->window).y) - 192);
        draw_text(rpg->window,
            rpg->npc_manager->current_dialog[rpg->npc_manager->dialog_pos],
            (int)(sfRenderWindow_getSize(rpg->window).x) / 2 - 360 + 50,
            (int)(sfRenderWindow_getSize(rpg->window).y) - 140);
        draw_text(rpg->window, rpg->npc_manager->current_npc->name,
            (int)(sfRenderWindow_getSize(rpg->window).x) / 2 - 360 + 50,
            (int)(sfRenderWindow_getSize(rpg->window).y) - 170);
    } else if (rpg->npc_manager->should_display_hover) {
        draw_text(rpg->window, rpg->npc_manager->dialog_hover, 0, 190);
    }
}