/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"
#include <my.h>
#include "stdlib.h"

void create_item(t_list *list, char *path, int id, sfVector2f pos)
{
    t_elem *new = malloc(sizeof(t_elem));

    new->object = create_dropped_item(path, pos, (sfIntRect){0, 0, 150, 150},
        id);
    new->printable = TRUE;
    new->next = NULL;
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->prev = NULL;
    } else {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
}

void create_item_not_dropped(t_list *list, char *path, int id, sfVector2f pos)
{
    t_elem *new = malloc(sizeof(t_elem));

    new->object = create_dropped_item(path, pos, (sfIntRect){0, 0, 150, 150},
        id);
    new->printable = FALSE;
    new->next = NULL;
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->prev = NULL;
    } else {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
}

void rm_first(t_list *list)
{
    if (list->first == NULL || list->last == NULL)
        return;
    if (list_len(list) == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
        list->first = list->first->next;
        free(list->first->prev);
        list->first->prev = NULL;
        if (list_len(list) == 1)
            list->last = list->first;
    }
}

void rm_last(t_list *list)
{
    if (list->first == NULL || list->last == NULL)
        return;
    if (list_len(list) == 1) {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    } else {
        list->last = list->last->prev;
        free(list->last->next);
        list->last->next = NULL;
        if (list_len(list) == 1)
            list->last = list->first;
    }
}

void free_list(t_list *list)
{
    while (list->first != NULL)
        rm_first(list);
    free(list);
}