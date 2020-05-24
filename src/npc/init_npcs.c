/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void init_raoult(sfFont *font, t_npc **npc)
{
    npc[4] = malloc(sizeof(t_npc));
    npc[4]->name = create_text("Professeur Raoult:", font, sfBlack, 25);
    npc[4]->pos = (sfVector2f){727, 258};
    npc[4]->chunk = (sfVector2i){0, 0};
    npc[4]->quest_dialog = raoult_init_dialog(font);
    npc[4]->quest_alt_dialog = raoult_init_alt_dialog(font);
    npc[4]->item_id = 0;
    npc[4]->xp_amount = 0;
    npc[5] = NULL;
}

void init_achille(sfFont *font, t_npc **npc)
{
    npc[3] = malloc(sizeof(t_npc));
    npc[3]->name = create_text("Achille:", font, sfBlack, 25);
    npc[3]->pos = (sfVector2f){718, 300};
    npc[3]->chunk = (sfVector2i){2, 0};
    npc[3]->quest_dialog = shopkeeper_init_dialog(font);
    npc[3]->quest_alt_dialog = shopkeeper_init_alt_dialog(font);
    npc[3]->item_id = 7;
    npc[3]->xp_amount = 0;
}

void init_lea(sfFont *font, t_npc **npc)
{
    npc[2] = malloc(sizeof(t_npc));
    npc[2]->name = create_text("Lea:", font, sfBlack, 25);
    npc[2]->pos = (sfVector2f){540, 30};
    npc[2]->chunk = (sfVector2i){2, 2};
    npc[2]->quest_dialog = lea_init_dialog(font);
    npc[2]->quest_alt_dialog = lea_init_alt_dialog(font);
    npc[2]->item_id = 3;
    npc[2]->xp_amount = 10;
}

void init_enzo(sfFont *font, t_npc **npc)
{
    npc[1] = malloc(sizeof(t_npc));
    npc[1]->name = create_text("Enzo:", font, sfBlack, 25);
    npc[1]->pos = (sfVector2f){1156, 480};
    npc[1]->chunk = (sfVector2i){2, 2};
    npc[1]->quest_dialog = enzo_init_dialog(font);
    npc[1]->quest_alt_dialog = enzo_init_alt_dialog(font);
    npc[1]->item_id = 4;
    npc[1]->xp_amount = 0;
}

void init_quentin(sfFont *font, t_npc **npc)
{
    npc[0] = malloc(sizeof(t_npc));
    npc[0]->name = create_text("Quentin:", font, sfBlack, 25);
    npc[0]->pos = (sfVector2f){866, 336};
    npc[0]->chunk = (sfVector2i){0, 2};
    npc[0]->quest_dialog = shopkeeper_init_dialog(font);
    npc[0]->quest_alt_dialog = shopkeeper_init_alt_dialog(font);
    npc[0]->item_id = 0;
    npc[0]->xp_amount = 0;
}