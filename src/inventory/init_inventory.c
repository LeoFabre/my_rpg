/*
** EPITECH PROJECT, 2024
** inventory-system
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include "rpg.h"

int *create_inv(int size)
{
    int x;
    int *res = malloc(sizeof(int *) * size);

    for (x = 0; x < size; x++) {
        res[x] = 0;
    }
    res[x] = 42;
    return (res);
}

void init_item_bis(t_rpg *rpg)
{
    rpg->character->inventory->items[6] = create_sprite(
        "ressources/potions/green.png");
    rpg->character->inventory->items[7] = create_sprite(
        "ressources/potions/purple.png");
    rpg->character->inventory->items[8] = create_sprite(
        "ressources/potions/red.png");
    rpg->character->inventory->items[9] = create_sprite(
        "ressources/potions/winered.png");
    rpg->character->inventory->items[10] = create_sprite(
        "ressources/potions/yellow.png");
    rpg->character->inventory->items[11] = NULL;
}

void init_items(t_rpg *rpg)
{
    rpg->character->inventory->items[0] = create_sprite(
        "ressources/potions/blue.png");
    rpg->character->inventory->items[1] = create_sprite(
        "ressources/potions/blue.png");
    rpg->character->inventory->items[2] = create_sprite(
        "ressources/potions/blue.png");
    rpg->character->inventory->items[3] = create_sprite("ressources/key.png");
    rpg->character->inventory->items[4] = create_sprite(
        "ressources/potions/blue.png");
    rpg->character->inventory->items[5] = create_sprite(
        "ressources/potions/darkgreen.png");
    init_item_bis(rpg);
}

void init_inventory(t_rpg *rpg)
{
    sfFont *font = sfFont_createFromFile("ressources/fonts/new_itemfont.ttf");
    rpg->character->inventory = malloc(sizeof(t_inv));
    rpg->character->inventory->new_item_delay = 0;
    rpg->character->inventory->inventory = create_inv(10);
    rpg->character->inventory->is_open = 0;
    rpg->character->inventory->is_pressed = 0;
    rpg->character->inventory->inv_sprite = create_sprite(
        "ressources/inventory/ui_inv.png");
    rpg->character->inventory->new_item = create_sprite(
        "ressources/inventory/new_item.png");
    rpg->character->inventory->items = malloc(sizeof(sfSprite *) * 12);
    rpg->character->inventory->new_itemtxt = create_text("NEW ITEM", font,
        sfColor_fromRGB(144, 185, 255), 20);
    init_items(rpg);
}

void destroy_inventory(t_rpg *rpg)
{
    sfSprite_destroy(rpg->character->inventory->inv_sprite);
    sfSprite_destroy(rpg->character->inventory->new_item);
    sfText_destroy(rpg->character->inventory->new_itemtxt);
    sfSprite_destroy(rpg->character->inventory->items[0]);
    sfSprite_destroy(rpg->character->inventory->items[1]);
    sfSprite_destroy(rpg->character->inventory->items[2]);
    sfSprite_destroy(rpg->character->inventory->items[3]);
    sfSprite_destroy(rpg->character->inventory->items[4]);
    sfSprite_destroy(rpg->character->inventory->items[5]);
    sfSprite_destroy(rpg->character->inventory->items[6]);
    sfSprite_destroy(rpg->character->inventory->items[7]);
    sfSprite_destroy(rpg->character->inventory->items[8]);
    sfSprite_destroy(rpg->character->inventory->items[9]);
    sfSprite_destroy(rpg->character->inventory->items[10]);
}