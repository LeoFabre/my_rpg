/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void get_dropped_item(t_rpg *rpg)
{
    sfVector2f pos_char = sfSprite_getPosition(rpg->character->obj->sprite);
    sfVector2f pos_item;
    t_elem *tmp = rpg->gameloop->list_items->first;

    for (; tmp != NULL; tmp = tmp->next) {
        pos_item = sfSprite_getPosition(tmp->object->sprite);
        if (pos_char.x <= pos_item.x + 30 && pos_char.x >= pos_item.x - 30 &&
            pos_char.y <= pos_item.y + 30 && pos_char.y >= pos_item.y - 30 &&
            tmp->printable == 1) {
            tmp->printable = 0;
            add_to_inventory(rpg, tmp->object->id);
            if (tmp->object->id >= 4)
                add_xp(rpg, 50);
        }
    }
}