/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void make_btn_rect_pause(t_button btn)
{
    sfIntRect res;

    res.top = 0;
    res.left = 0;
    res.width = sfSprite_getTextureRect(btn.sprite).width / 3;
    res.height = sfSprite_getTextureRect(btn.sprite).height;
    sfSprite_setTexture(btn.sprite, btn.texture, sfTrue);
    sfSprite_setTextureRect(btn.sprite, res);
}

void init_btns_rects_pause(t_rpg *rpg)
{
    make_btn_rect_pause(rpg->menu->btns[STARTBTN]);
    make_btn_rect_pause(rpg->menu->btns[QUITBTN]);
    make_btn_rect_pause(rpg->menu->btns[RETRYBTN]);
    make_btn_rect_pause(rpg->menu->btns[MENUBTN]);
}

void animate_btn_pause(t_rpg *mydefender, t_button *btn)
{
    sfIntRect texture_rect = sfSprite_getTextureRect(btn->sprite);

    if (btn->state == BTN_PRESSED && cur_on_hitbox(mydefender, btn->sprite)) {
        texture_rect.left = texture_rect.width * (btn->state - 1);
        sfSprite_setTextureRect(btn->sprite, texture_rect);
        return;
    } else if (cur_on_hitbox(mydefender, btn->sprite) == 0) {
        btn->state = BTN_IDLE;
    } else if (cur_on_hitbox(mydefender, btn->sprite) == 1) {
        btn->state = BTN_HOVER;
    }
    texture_rect.left = texture_rect.width * (btn->state - 1);
    sfSprite_setTextureRect(btn->sprite, texture_rect);
}

void animate_btns_pause(t_rpg *rpg)
{
    animate_btn(rpg, &rpg->menu->btns[STARTBTN]);
    animate_btn(rpg, &rpg->menu->btns[QUITBTN]);
    animate_btn(rpg, &rpg->menu->btns[RETRYBTN]);
    animate_btn(rpg, &rpg->menu->btns[MENUBTN]);
}