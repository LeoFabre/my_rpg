/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_listener
*/

#include "rpg.h"

void check_for_interaction(t_rpg *rpg, void (*process)(t_rpg *, t_npc *, int))
{
    t_npc **npcs = rpg->npc_manager->npc;
    for (int i = 0; npcs[i] != NULL; i++) {
        if (charac_can_interact(rpg, npcs[i])) {
            process(rpg, npcs[i], i);
            return;
        }
    }
    rpg->npc_manager->should_display_hover = 0;
}

void open_dialog(t_rpg *rpg, t_npc *npc, int npc_pos)
{
    rpg->npc_manager->isKeyDown = 1;
    rpg->npc_manager->should_display_hover = 0;
    rpg->character->move_state = IDLE;
    rpg->audio->run = 0;
    rpg->audio->update = 1;
    rpg->npc_manager->is_in_dialog = sfTrue;
    rpg->npc_manager->dialog_pos = 0;
    if ((npc->chunk.x == 0 && npc->chunk.y == 0 &&
        rpg->character->quests->collect != 7) ||
        (rpg->npc_manager->npc_status[npc_pos] != 0))
        rpg->npc_manager->current_dialog = npc->quest_alt_dialog;
    else
        rpg->npc_manager->current_dialog = npc->quest_dialog;
    rpg->npc_manager->npc_status[npc_pos] = 1;
    rpg->npc_manager->current_npc = npc;
}

void display_hover(t_rpg *rpg, t_npc *npc, int npc_pos)
{
    (void)(npc);
    (void)(npc_pos);
    rpg->npc_manager->should_display_hover = 1;
}

void npc_dialog_progress(t_rpg *rpg)
{
    rpg->npc_manager->isKeyDown = 1;
    if (rpg->npc_manager->current_npc->quest_dialog[
        rpg->npc_manager->dialog_pos + 1] == NULL) {
        if (rpg->npc_manager->current_npc->xp_amount != 0) {
            add_xp(rpg, rpg->npc_manager->current_npc->xp_amount);
            rpg->npc_manager->current_npc->xp_amount = 0;
        }
        if (rpg->npc_manager->current_npc->item_id != 0) {
            add_to_inventory(rpg, rpg->npc_manager->current_npc->item_id);
            rpg->npc_manager->current_npc->item_id = 0;
        }
        rpg->npc_manager->is_in_dialog = sfFalse;
        if (rpg->npc_manager->current_npc->chunk.x == 0 &&
            rpg->npc_manager->current_npc->chunk.y == 0 &&
            rpg->character->quests->collect == 7) {
            end_game(rpg);
        }
    } else {
        rpg->npc_manager->dialog_pos++;
    }
}

void npc_event_listener(t_rpg *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && rpg->npc_manager->isKeyDown == 0) {
        if (rpg->npc_manager->is_in_dialog == sfFalse)
            check_for_interaction(rpg, &open_dialog);
        else
            npc_dialog_progress(rpg);
    } else {
        if (rpg->npc_manager->is_in_dialog == sfFalse)
            check_for_interaction(rpg, &display_hover);
        rpg->npc_manager->isKeyDown = 0;
    }
}