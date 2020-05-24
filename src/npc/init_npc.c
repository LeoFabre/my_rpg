/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_npc
*/

#include "rpg.h"

void init_npc_manager(t_rpg *rpg, t_npc **npcs)
{
    t_npc_manager *npc_manager = malloc(sizeof(t_npc_manager));
    npc_manager->dialog_sprite = create_sprite("ressources/hud/textbox.png");
    npc_manager->is_in_dialog = sfFalse;
    npc_manager->npc_status = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        npc_manager->npc_status[i] = 0;
    npc_manager->current_npc = NULL;
    npc_manager->dialog_pos = 0;
    npc_manager->npc = npcs;
    npc_manager->isKeyDown = 0;
    npc_manager->should_display_hover = 0;
    npc_manager->dialog_hover = create_text("Press E to discuss",
    sfFont_createFromFile("ressources/fonts/new_itemfont.ttf"), sfBlack,
    25);
    rpg->npc_manager = npc_manager;
}

void init_npc(t_rpg *rpg)
{
    sfFont *font = sfFont_createFromFile("ressources/fonts/new_itemfont.ttf");
    t_npc **npc = malloc(sizeof(t_npc *) * 6);

    init_quentin(font, npc);
    init_enzo(font, npc);
    init_lea(font, npc);
    init_achille(font, npc);
    init_raoult(font, npc);
    init_npc_manager(rpg, npc);
    rpg->npc_manager->npc = npc;
}

void destroy_npc(t_rpg *rpg)
{
    sfSprite_destroy(rpg->npc_manager->dialog_sprite);
    sfText_destroy(rpg->npc_manager->dialog_hover);
    sfText_destroy(rpg->npc_manager->npc[0]->name);
    sfText_destroy(rpg->npc_manager->npc[1]->name);
    sfText_destroy(rpg->npc_manager->npc[2]->name);
    sfText_destroy(rpg->npc_manager->npc[3]->name);
    sfText_destroy(rpg->npc_manager->npc[4]->name);
}