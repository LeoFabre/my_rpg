/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void init_items_map(t_rpg *rpg)
{
    create_item_not_dropped(rpg->gameloop->list_items, "ressources/key.png", 3,
        (sfVector2f){0, 0});
    create_item_not_dropped(rpg->gameloop->list_items,
        "ressources/potions/blue.png", 4, (sfVector2f){0, 0});
    create_item_not_dropped(rpg->gameloop->list_items,
        "ressources/potions/darkgreen.png", 5, (sfVector2f){0, 0});
    create_item(rpg->gameloop->list_items, "ressources/potions/green.png", 6,
        (sfVector2f){750, 70});
    create_item_not_dropped(rpg->gameloop->list_items,
        "ressources/potions/red.png", 8, (sfVector2f){0, 0});
    create_item_not_dropped(rpg->gameloop->list_items,
        "ressources/potions/purple.png", 7, (sfVector2f){0, 0});
    create_item_not_dropped(rpg->gameloop->list_items, "ressources/potions/winered.png", 9,
        (sfVector2f){0, 0});
    create_item_not_dropped(rpg->gameloop->list_items,
        "ressources/potions/yellow.png", 10, (sfVector2f){0, 0});
}