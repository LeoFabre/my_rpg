/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void debug_print_moblist(t_moblist *list)
{
    t_mob *current = list->first;
    int i = 0;

    my_printf("--== DEBUG ==--\n");
    if (list->first == NULL && list->last == NULL) {
        my_printf("LIST IS EMPTY !!\n");
        my_printf("--== END DEBUG ==--\n");
        return;
    }
    for (; current != NULL; i++, current = current->next) {
        my_printf("id : %i\n", current->health);
    }
    my_printf("--== END DEBUG ==--\n");
}

void init_mob_bat(char *filepath, sfVector2f *pos, int *chunk, t_mob *new)
{
    new->id = BAT;
    new->health = 100;
    new->pos = (*pos);
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(filepath, NULL);
    new->rect = (sfIntRect){0, 0, 16, 24};
    new->chunk[0] = chunk[0];
    new->chunk[1] = chunk[1];
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setTexture(new->sprite, new->texture, sfFalse);
    sfSprite_setPosition(new->sprite, (*pos));
    sfSprite_setScale(new->sprite, (sfVector2f){6, 6});
}

void create_mob_bat(t_moblist *moblist, char *filepath, sfVector2f pos,
    int chunk[2])
{
    t_mob *new = malloc(sizeof(t_mob));

    init_mob_bat(filepath, &pos, chunk, new);
    new->next = NULL;
    if (moblist->first == NULL && moblist->last == NULL) {
        moblist->first = new;
        moblist->last = new;
        new->prev = NULL;
    } else {
        moblist->last->next = new;
        new->prev = moblist->last;
        moblist->last = new;
    }
}
