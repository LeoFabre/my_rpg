/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** gameloop_events
*/

#include "rpg.h"

void inventory_event(t_rpg *rpg)
{
    if (rpg->character->quests->is_open == 0) {
        if (rpg->character->inventory->is_pressed == 0)
            rpg->character->inventory->is_pressed = 1;
        else
            rpg->character->inventory->is_pressed = 0;
        if (rpg->character->inventory->is_open == 0 &&
            rpg->character->inventory->is_pressed == 0)
            open_inventory(rpg);
        else if (rpg->character->inventory->is_open == 1 &&
            rpg->character->inventory->is_pressed == 0)
            close_inventory(rpg);
    }
}

void quest_event(t_rpg *rpg)
{
    if (rpg->character->inventory->is_open == 0) {
        if (rpg->character->quests->is_pressed == 0)
            rpg->character->quests->is_pressed = 1;
        else
            rpg->character->quests->is_pressed = 0;
        if (rpg->character->quests->is_open == 0 &&
            rpg->character->quests->is_pressed == 0)
            open_qbook(rpg);
        else if (rpg->character->quests->is_open == 1 &&
            rpg->character->quests->is_pressed == 0)
            close_qbook(rpg);
    }
}

void pause_event(t_rpg *rpg)
{
    if (rpg->gamestate != PAUSELOOP) {
        rpg->old_gamestate = rpg->gamestate;
        rpg->gamestate = PAUSELOOP;
    }
}

void game_event(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    npc_event_listener(rpg);
    if (rpg->npc_manager->is_in_dialog)
        return;
    else {
        if (rpg->audio->run == 1) {
            rpg->audio->run = 0;
            rpg->audio->update = 1;
            sfMusic_stop(rpg->audio->run_sound);
        }
    }
}

void gameloop_events(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    game_event(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        quest_event(rpg);
    else if (sfKeyboard_isKeyPressed(sfKeyI))
        inventory_event(rpg);
    else if (sfKeyboard_isKeyPressed(sfKeyEscape))
        pause_event(rpg);
}