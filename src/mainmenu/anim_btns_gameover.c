/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void make_btn_rect_gameover(t_button btn)
{
    sfIntRect res;

    res.top = 0;
    res.left = 0;
    res.width = sfSprite_getTextureRect(btn.sprite).width / 3;
    res.height = sfSprite_getTextureRect(btn.sprite).height;
    sfSprite_setTexture(btn.sprite, btn.texture, sfTrue);
    sfSprite_setTextureRect(btn.sprite, res);
}

void init_btns_rects_gameover(t_rpg *rpg)
{
    make_btn_rect_gameover(rpg->menu->btns[QUITBTN]);
    make_btn_rect_gameover(rpg->menu->btns[RETRYBTN]);
    make_btn_rect_gameover(rpg->menu->btns[MENUBTN]);
}

void animate_btns_gameover(t_rpg *rpg)
{
    animate_btn(rpg, &rpg->menu->btns[QUITBTN]);
    animate_btn(rpg, &rpg->menu->btns[RETRYBTN]);
    animate_btn(rpg, &rpg->menu->btns[MENUBTN]);
}