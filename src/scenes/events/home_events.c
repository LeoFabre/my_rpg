/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** home_events
*/

#include "rpg.h"

void home_events(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(rpg->window);
}