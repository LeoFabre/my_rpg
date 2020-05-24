/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

int list_len(t_list *list)
{
    t_elem *current = list->first;
    int i = 0;

    if (list->first != NULL && list->last != NULL)
        for (; current != NULL; i++, current = current->next);
    return i;
}

void debug_print_list(t_list *list)
{
    t_elem *current = list->first;
    int i = 0;

    my_printf("--== DEBUG ==--\n");
    if (list->first == NULL && list->last == NULL) {
        my_printf("LIST IS EMPTY !!\n");
        my_printf("--== END DEBUG ==--\n");
        return;
    } else {
        my_printf("id first = %i\n", list->first->object->id);
        my_printf("id last = %i\n", list->last->object->id);
    }
    for (; current != NULL; i++, current = current->next) {
        my_printf("id : %i\n", current->object->id);
    }
    my_printf("--== END DEBUG ==--\n");
}

t_list *init_list(void)
{
    t_list *list = malloc(sizeof(t_list));

    list->first = NULL;
    list->last = NULL;
    return list;
}

void add_elem_to_end(t_elem *new, t_rpg *rpg)
{
    new->next = NULL;
    if (rpg->gameloop->list_items->first == NULL &&
        rpg->gameloop->list_items->last == NULL) {
        rpg->gameloop->list_items->first = new;
        rpg->gameloop->list_items->last = new;
        new->prev = NULL;
    } else {
        rpg->gameloop->list_items->last->next = new;
        new->prev = rpg->gameloop->list_items->last;
        rpg->gameloop->list_items->last = new;
    }
}

void add_elem_to_start(t_elem *new, t_rpg *rpg)
{
    new->prev = NULL;
    if (rpg->gameloop->list_items->first == NULL &&
        rpg->gameloop->list_items->last == NULL) {
        rpg->gameloop->list_items->first = new;
        rpg->gameloop->list_items->last = new;
        new->next = NULL;
    } else {
        new->next = rpg->gameloop->list_items->first;
        rpg->gameloop->list_items->first->prev = new;
        rpg->gameloop->list_items->first = new;
    }
}