/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

t_button make_btn(char *filepath)
{
    t_button res;

    res.sprite = sfSprite_create();
    res.texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(res.sprite, res.texture, sfFalse);
    res.state = BTN_IDLE;
    return res;
}

t_button *make_btns(void)
{
    t_button *buttons = malloc(sizeof(t_button) * 5);

    buttons[STARTBTN] = make_btn("ressources/mainmenu/startbtn.png");
    buttons[QUITBTN] = make_btn("ressources/mainmenu/quitbtn.png");
    buttons[RETRYBTN] = make_btn("ressources/mainmenu/retrybtn.png");
    buttons[MENUBTN] = make_btn("ressources/mainmenu/menubtn.png");
    buttons[RESUMEBTN] = make_btn("ressources/mainmenu/resumebtn.png");
    return buttons;
}

void init_menu(t_rpg *rpg)
{
    rpg->menu = malloc(sizeof(t_menuobjs));
    rpg->menu->mainlogo = make_obj("ressources/mainmenu/mainlogo.png");
    rpg->menu->pauselogo = make_obj("ressources/mainmenu/pauselogo.png");
    rpg->menu->gameoverlogo = make_obj("ressources/mainmenu/gameover.png");
    rpg->menu->bg = make_obj("ressources/mainmenu/bg.png");
    rpg->menu->btns = make_btns();
    init_btns_rects(rpg);
    init_logo_pos(rpg, rpg->menu->pauselogo);
    init_logo_pos(rpg, rpg->menu->mainlogo);
    init_logo_pos(rpg, rpg->menu->gameoverlogo);
    move_btns(rpg);
}