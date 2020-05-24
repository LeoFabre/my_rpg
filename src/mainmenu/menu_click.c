/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void manage_menu_release_click(t_rpg *rpg)
{
    sfSound *start;

    if (cur_on_hitbox(rpg, rpg->menu->btns[STARTBTN].sprite) == 1) {
        start = create_sound("ressources/sounds/startgame.ogg");
        sfSound_play(start);
        init_all(rpg);
        rpg->gamestate = GAMELOOP;
        sfSound_destroy(start);
        set_music(rpg, 1, TRUE);
        sfRenderWindow_clear(rpg->window, sfBlack);
    } else if (cur_on_hitbox(rpg, rpg->menu->btns[QUITBTN].sprite) == 1)
        sfRenderWindow_close(rpg->window);
}

void manage_menu_click(t_rpg *rpg)
{
    if (cur_on_hitbox(rpg, rpg->menu->btns[STARTBTN].sprite) == 1)
        rpg->menu->btns[STARTBTN].state = BTN_PRESSED;
    else if (cur_on_hitbox(rpg, rpg->menu->btns[QUITBTN].sprite) == 1)
        rpg->menu->btns[QUITBTN].state = BTN_PRESSED;
    animate_btns(rpg);
}