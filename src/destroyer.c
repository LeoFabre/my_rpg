/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void destroy_music(t_rpg *rpg)
{
    if (rpg->audio->music[0] != NULL)
        sfMusic_destroy(rpg->audio->music[0]);
    if (rpg->audio->music[1] != NULL)
        sfMusic_destroy(rpg->audio->music[1]);
    if (rpg->character->inventory->sounds[0] != NULL)
        sfSound_destroy(rpg->character->inventory->sounds[0]);
    if (rpg->character->inventory->sounds[1] != NULL)
        sfSound_destroy(rpg->character->inventory->sounds[1]);
    if (rpg->audio->fight_sound != NULL)
        sfSound_destroy(rpg->audio->fight_sound);
}

void destroy_all(t_rpg *rpg)
{
//    destroy_music(rpg);
    destroy_quests(rpg);
    destroy_inventory(rpg);
    destroy_npc(rpg);
}