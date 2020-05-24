/*
** EPITECH PROJECT, 2024
** inventory_system
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void draw_inventory(t_rpg *rpg)
{
    int add_to_x = 332;

    drawer(rpg->window, rpg->character->inventory->inv_sprite,
        (int)(sfRenderWindow_getSize(rpg->window).x / 2) - 400,
        (int)(sfRenderWindow_getSize(rpg->window).y / 2) - 250);
    for (int x = 0; x < 10; x++) {
        if (rpg->character->inventory->inventory[x] != 0) {
            sfSprite_setScale(rpg->character->inventory->items[\
                rpg->character->inventory->inventory[x]],
                (sfVector2f){0.5, 0.5});
            drawer(rpg->window, rpg->character->inventory->items[\
                rpg->character->inventory->inventory[x]],
                (int)(sfRenderWindow_getSize(rpg->window).x / 2 - add_to_x),
                (int)(sfRenderWindow_getSize(rpg->window).y / 2 + 60));
            if (x < 3)
                add_to_x -= 74;
            else
                add_to_x -= 70;
        }
    }
}

void open_inventory(t_rpg *rpg)
{
    sfSound_play(rpg->character->inventory->sounds[0]);
    rpg->character->inventory->is_open = 1;
}

void close_inventory(t_rpg *rpg)
{
    sfSound_play(rpg->character->inventory->sounds[1]);
    rpg->character->inventory->is_open = 0;
}

int add_to_inventory(t_rpg *rpg, int itemid)
{
    int new_slot = -1;

    for (int x = 0; x < 10; x++) {
        if (rpg->character->inventory->inventory[x] == 0) {
            new_slot = x;
            break;
        }
    }
    if (new_slot == -1)
        return (84);
    if (itemid >= 4 && itemid <= 10)
        rpg->character->quests->collect++;
    rpg->character->inventory->new_item_delay = 300;
    rpg->character->inventory->inventory[new_slot] = itemid;
    my_printf("[INV]: Add (%d) at slot (%d)\n", itemid, new_slot);
    return (0);
}

int remove_to_inventory(t_rpg *rpg, int slotid)
{
    my_printf("[INV]: Remove (%d) at slot (%d)\n",
        rpg->character->inventory->inventory[slotid], slotid);
    rpg->character->inventory->inventory[slotid] = 0;
    return (0);
}