/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/
#include "rpg.h"

void print_help(void)
{
    my_printf("DESCRIPTION\n");
    my_printf("USAGE\n\n");
}

int main(int ac, char **av)
{
    t_rpg *rpg = init_struct_game();

    if (ac == 2 && (my_strcmp(av[1], "-h") == 0)) {
        print_help();
        return (0);
    }
    game(rpg);
    return 0;
}