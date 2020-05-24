/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void gameoverloop(t_rpg *rpg)
{
    animate_btns_gameover(rpg);
    display_gameover(rpg);
    sfRenderWindow_display(rpg->window);
}

void display_gameover(t_rpg *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    display_backgroud(rpg);
    display_items(rpg);
    animate_btns(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->gameoverlogo->spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->btns[RETRYBTN].sprite,
        NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->btns[QUITBTN].sprite,
        NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->btns[MENUBTN].sprite,
        NULL);
    sfRenderWindow_display(rpg->window);
}