/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

float center_y_btn(t_rpg *rpg, t_button *btn, float div_offset)
{
    float winy = (float)sfWindow_getSize((const sfWindow *)rpg->window).y;

    return (winy / div_offset) -
        (sfSprite_getLocalBounds(btn->sprite).height / 2);
}

float center_x_btn(t_rpg *rpg, t_button *btn)
{
    float winx = (float)sfWindow_getSize((const sfWindow *)rpg->window).x;

    return ((winx / 2) - (sfSprite_getLocalBounds(btn->sprite).width / 2));
}

void init_logo_pos(t_rpg *rpg, t_obj *logo)
{
    float winx = (float)sfWindow_getSize((const sfWindow *)rpg->window).x;
    float winy = (float)sfWindow_getSize((const sfWindow *)rpg->window).y;
    sfVector2f logopos = {0, 0};

    logopos.x =
        ((float)winx / 2) - (sfSprite_getLocalBounds(logo->spr).width / 2.0f);
    logopos.y =
        ((float)winy / 3.2f) - (sfSprite_getLocalBounds(logo->spr).height);
    sfSprite_move(logo->spr, logopos);
}

void move_btns(t_rpg *rpg)
{
    sfSprite_move(rpg->menu->btns[STARTBTN].sprite,
        (sfVector2f){center_x_btn(rpg, &rpg->menu->btns[STARTBTN]),
            center_y_btn(rpg, &rpg->menu->btns[STARTBTN], 2)});
    sfSprite_move(rpg->menu->btns[QUITBTN].sprite,
        (sfVector2f){center_x_btn(rpg, &rpg->menu->btns[QUITBTN]),
            center_y_btn(rpg, &rpg->menu->btns[QUITBTN], 1.6f)});
    sfSprite_move(rpg->menu->btns[RETRYBTN].sprite,
        (sfVector2f){center_x_btn(rpg, &rpg->menu->btns[RETRYBTN]),
            center_y_btn(rpg, &rpg->menu->btns[RETRYBTN], 2)});
    sfSprite_move(rpg->menu->btns[RESUMEBTN].sprite,
        (sfVector2f){center_x_btn(rpg, &rpg->menu->btns[RESUMEBTN]),
            center_y_btn(rpg, &rpg->menu->btns[RESUMEBTN], 2)});
    sfSprite_move(rpg->menu->btns[MENUBTN].sprite,
        (sfVector2f){center_x_btn(rpg, &rpg->menu->btns[MENUBTN]),
            center_y_btn(rpg, &rpg->menu->btns[MENUBTN], 1.25f)});
}