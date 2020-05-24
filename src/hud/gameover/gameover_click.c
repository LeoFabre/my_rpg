/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void manage_gameover_release_click(t_rpg *rpg)
{
    if (cur_on_hitbox(rpg, rpg->menu->btns[RETRYBTN].sprite) == 1) {
        init_all(rpg);
        rpg->gamestate = GAMELOOP;
        set_music(rpg, 1, FALSE);
        sfRenderWindow_clear(rpg->window, sfBlack);
    } else if (cur_on_hitbox(rpg, rpg->menu->btns[QUITBTN].sprite) == 1) {
        sfRenderWindow_close(rpg->window);
    } else if (cur_on_hitbox(rpg, rpg->menu->btns[MENUBTN].sprite) == 1) {
        my_printf("RELEASED MENU BTN\n");
        rpg->gamestate = MENULOOP;
    }
}

void manage_gameover_click(t_rpg *rpg)
{
    if (cur_on_hitbox(rpg, rpg->menu->btns[RETRYBTN].sprite) == 1) {
        rpg->menu->btns[RETRYBTN].state = BTN_PRESSED;
    } else if (cur_on_hitbox(rpg, rpg->menu->btns[QUITBTN].sprite) == 1)
        rpg->menu->btns[QUITBTN].state = BTN_PRESSED;
    else if (cur_on_hitbox(rpg, rpg->menu->btns[MENUBTN].sprite) == 1)
        rpg->menu->btns[MENUBTN].state = BTN_PRESSED;
    animate_btns(rpg);
}