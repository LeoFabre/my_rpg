/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void init_mob_rat(char *filepath, sfVector2f *pos, int *chunk, t_mob *new)
{
    new->id = RAT;
    new->health = 100;
    new->pos = (*pos);
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(filepath, NULL);
    new->rect = (sfIntRect){0, 0, 64, 64};
    new->chunk[0] = chunk[0];
    new->chunk[1] = chunk[1];
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setTexture(new->sprite, new->texture, sfFalse);
    sfSprite_setPosition(new->sprite, (*pos));
    sfSprite_setScale(new->sprite, (sfVector2f){3, 3});
}

void create_mob_rat(t_moblist *moblist, char *filepath, sfVector2f pos,
    int chunk[2])
{
    t_mob *new = malloc(sizeof(t_mob));

    init_mob_rat(filepath, &pos, chunk, new);
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
