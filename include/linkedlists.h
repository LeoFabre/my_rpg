/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/
#ifndef MUL_MY_RPG_2019_LINKEDLISTS_H
#define MUL_MY_RPG_2019_LINKEDLISTS_H

typedef struct s_list t_list;
typedef struct s_elem t_elem;
typedef struct s_game_item t_game_item;

typedef struct s_elem {
    t_game_item *object;
    int printable;
    t_elem *next;
    t_elem *prev;
} t_elem;

typedef struct s_list {
    t_elem *first;
    t_elem *last;
} t_list;

void debug_print_list(t_list *list);

#endif //MUL_MY_RPG_2019_LINKEDLISTS_H
