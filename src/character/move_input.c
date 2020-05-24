/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void check_input(t_rpg *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        rpg->character->move_state = DOWN;
        move_down(rpg);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        rpg->character->move_state = RIGHT;
        move_right(rpg);
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        rpg->character->move_state = LEFT;
        move_left(rpg);
    } else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        rpg->character->move_state = UP;
        move_up(rpg);
    } else
        rpg->character->move_state = IDLE;
}