/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/
#include "rpg.h"

void analyse_menu_events(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(rpg->window);
    if (rpg->event.type == sfEvtMouseButtonPressed) {
        rpg->clickstate = CLICK_PRESSED;
        if (rpg->gamestate == MENULOOP) {
            manage_menu_click(rpg);
        }
    }
    if (rpg->event.type == sfEvtMouseButtonReleased) {
        rpg->clickstate = CLICK_RELEASED;
        if (rpg->gamestate == MENULOOP)
            manage_menu_release_click(rpg);
    }
}

void analyse_pausemenu_events(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed) {
        sfRenderWindow_close(rpg->window);
    }
    if (rpg->event.type == sfEvtMouseButtonPressed) {
        rpg->clickstate = CLICK_PRESSED;
        if (rpg->gamestate == PAUSELOOP) {
            manage_pausemenu_click(rpg);
        }
    }
    if (rpg->event.type == sfEvtMouseButtonReleased) {
        rpg->clickstate = CLICK_RELEASED;
        if (rpg->gamestate == PAUSELOOP) {
            manage_pausemenu_release_click(rpg);
        }
    }
}

void analyse_gameover_events(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed) {
        sfRenderWindow_close(rpg->window);
    }
    if (rpg->event.type == sfEvtMouseButtonPressed) {
        rpg->clickstate = CLICK_PRESSED;
        if (rpg->gamestate == GAMEOVERLOOP) {
            manage_gameover_click(rpg);
        }
    }
    if (rpg->event.type == sfEvtMouseButtonReleased) {
        rpg->clickstate = CLICK_RELEASED;
        if (rpg->gamestate == GAMEOVERLOOP) {
            manage_gameover_release_click(rpg);
        }
    }
}