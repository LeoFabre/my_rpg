/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void create_mobs_pos(t_moblist *moblist)
{
    char *batpath = "ressources/bat.png";
    char *ratpath = "ressources/rat.png";

    create_mob_bat(moblist, batpath, (sfVector2f){1045, 290}, (int[2]){1, 0});
    create_mob_rat(moblist, ratpath, (sfVector2f){782, 80}, (int[2]){1, 0});
    create_mob_bat(moblist, batpath, (sfVector2f){522, 200}, (int[2]){1, 1});
    create_mob_rat(moblist, ratpath, (sfVector2f){1152, 145}, (int[2]){1, 1});
    create_mob_bat(moblist, batpath, (sfVector2f){676, 283}, (int[2]){1, 2});
    create_mob_rat(moblist, ratpath, (sfVector2f){478, 205}, (int[2]){0, 2});
    create_mob_bat(moblist, batpath, (sfVector2f){605, 645}, (int[2]){0, 1});
    create_mob_rat(moblist, ratpath, (sfVector2f){1075, 620}, (int[2]){0, 0});
    create_mob_bat(moblist, batpath, (sfVector2f){582, 230}, (int[2]){2, 1});
    create_mob_rat(moblist, ratpath, (sfVector2f){946, 600}, (int[2]){2, 2});
    create_mob_bat(moblist, batpath, (sfVector2f){400, 100}, (int[2]){2, 2});
}