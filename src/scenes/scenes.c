/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void move_chunks(t_rpg *rpg)
{
    move_chunk_top(rpg);
    update_move_up(rpg);
    move_chunk_down(rpg);
    update_move_down(rpg);
    move_chunk_right(rpg);
    update_move_right(rpg);
    move_chunk_left(rpg);
    update_move_left(rpg);
}

void check_fight(t_rpg *rpg)
{
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    sfVector2f pos_item;
    t_mob *tmp = rpg->gameloop->moblist->first;
    float radius = 150.f;

    for (; tmp != NULL; tmp = tmp->next) {
        pos_item = sfSprite_getPosition(tmp->sprite);
        if (pos_char.x <= pos_item.x + (radius - 40) &&
            pos_char.x >= pos_item.x - radius &&
            pos_char.y <= pos_item.y + (radius - 40) &&
            pos_char.y >= pos_item.y - radius && tmp->health >= 1 &&
            rpg->character->current_chunk[CHUNK_Y] == tmp->chunk[CHUNK_Y] &&
            rpg->character->current_chunk[CHUNK_X] == tmp->chunk[CHUNK_X] &&
            rpg->gameloop->camera_mouv == FALSE) {
            my_printf(" --|| Entered Fight ||-- %i\n", tmp->id);
            rpg->fight->opponent = tmp;
            rpg->fight->is_player_turn = TRUE;
            rpg->gamestate = FIGHTLOOP;
        }
    }
}

void gameloop(t_rpg *rpg)
{
    check_input(rpg);
    animate_character(rpg, rpg->character->move_state);
    get_dropped_item(rpg);
    check_fight(rpg);
    move_chunks(rpg);
    display_loop(rpg);
}

void menuloop(t_rpg *rpg)
{
    animate_btns(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->bg->spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->mainlogo->spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->btns[STARTBTN].sprite,
        NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->btns[QUITBTN].sprite,
        NULL);
    sfRenderWindow_display(rpg->window);
}