/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

int get_last_item(t_rpg *rpg)
{
    int x;

    for (x = 0; x < 10; x++) {
        if (rpg->character->inventory->inventory[x] != 0 &&
            rpg->character->inventory->inventory[x + 1] == 0)
            return (rpg->character->inventory->inventory[x]);
    }
    return (0);
}

void display_new_item(t_rpg *rpg)
{
    char *text = malloc(
        sizeof(char) * (my_strlen(get_item_name(get_last_item(rpg))) + 2));

    text[0] = '+';
    text[1] = ' ';
    text[2] = '\0';
    text = my_strcat(text, get_item_name(get_last_item(rpg)));
    drawer(rpg->window, rpg->character->inventory->new_item,
        (int)(sfRenderWindow_getSize(rpg->window).x / 2) + 390, 10);
    sfText_setString(rpg->character->inventory->new_itemtxt, text);
    draw_text(rpg->window, rpg->character->inventory->new_itemtxt,
        (int)(sfRenderWindow_getSize(rpg->window).x / 2) + 430, 55);
    sfSprite_setScale(rpg->character->inventory->items[get_last_item(rpg)],
        (sfVector2f){0.9, 0.9});
    drawer(rpg->window, rpg->character->inventory->items[get_last_item(rpg)],
        (int)(sfRenderWindow_getSize(rpg->window).x / 2) + 600, 0);
    rpg->character->inventory->new_item_delay--;
}

void display_inventory(t_rpg *rpg)
{
    if (rpg->character->inventory->is_open == 1)
        draw_inventory(rpg);
    if (rpg->character->inventory->new_item_delay != 0) {
        sfSprite_setScale(rpg->character->inventory->new_item,
            (sfVector2f){0.45, 0.35});
        display_new_item(rpg);
    }
}