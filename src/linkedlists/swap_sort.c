/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"
#include "my.h"
#include "stdio.h"

int swap_for_first_last(t_elem *target, t_rpg *rpg)
{
    if (target == rpg->gameloop->list_items->first) {
        target->next->prev = NULL;
        target->prev = target->next;
        rpg->gameloop->list_items->first = target->next;
        target->next = target->prev->next;
        target->next->prev = target;
        target->prev->next = target;
        return 0;
    } else if (target == rpg->gameloop->list_items->last->prev) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        target->prev->next->next = target;
        target->prev = target->next;
        rpg->gameloop->list_items->last = target;
        target->next = NULL;
        return 0;
    }
    return 1;
}

void swap_with_next(t_elem *target, t_rpg *rpg)
{
    if (target == rpg->gameloop->list_items->last)
        return;
    if (swap_for_first_last(target, rpg) != 0) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        target->next = target->next->next;
        target->prev->next->next = target;
        target->next->prev = target;
        target->prev = target->prev->next;
    }
}

void do_pass(t_rpg *rpg, int len, t_elem *current)
{
    current = rpg->gameloop->list_items->first;
    for (int i = 0; i < len - 1; i++, current = current->next)
        if (current->object->id > current->next->object->id) {
            swap_with_next(current, rpg);
            current = current->prev;
        }
}

void sort_elems(t_rpg *rpg)
{
    int len = list_len(rpg->gameloop->list_items);
    int nb_passes = 0;
    t_elem *current = NULL;

    for (nb_passes = 0; nb_passes < len - 1; nb_passes++)
        do_pass(rpg, len, current);
}