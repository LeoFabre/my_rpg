/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc_interaction
*/

#include "rpg.h"

int charac_can_interact(t_rpg *rpg, t_npc *npc)
{
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    sfVector2f pos_min_char = npc->pos;
    sfVector2f pos_max_char = (sfVector2f){npc->pos.x + 100, npc->pos.y + 100};
    if (!(pos_char.x >= pos_min_char.x && pos_char.x <= pos_max_char.x) ||
        !(pos_char.y >= pos_min_char.y && pos_char.y <= pos_max_char.y) ||
        rpg->character->current_chunk[CHUNK_X] != npc->chunk.x ||
        rpg->character->current_chunk[CHUNK_Y] != npc->chunk.y)
        return (0);
    return (1);
}