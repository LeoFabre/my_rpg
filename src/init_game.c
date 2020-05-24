/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void init_mobs(t_rpg *rpg)
{
    t_moblist *moblist = malloc(sizeof(t_moblist));

    moblist->first = NULL;
    moblist->last = NULL;
    moblist->clk_bat = malloc(sizeof(sfClock *));
    moblist->clk_bat[0] = sfClock_create();
    moblist->clk_bat[1] = sfClock_create();
    moblist->clk_rat = malloc(sizeof(sfClock *));
    moblist->clk_rat[0] = sfClock_create();
    moblist->clk_rat[1] = sfClock_create();
    create_mobs_pos(moblist);
    rpg->gameloop->moblist = moblist;
}

void init_struct_loop(t_rpg *rpg)
{
    rpg->gameloop = malloc(sizeof(t_gameloop));
    rpg->gameloop->list_items = init_list();
    init_items_map(rpg);
    rpg->gameloop->anim_items = sfClock_create();
    rpg->gameloop->camera_clk = sfClock_create();
    rpg->gameloop->camera_mouv = 0;
    create_background(rpg);
}

void init_particles(t_rpg *rpg)
{
    rpg->particles = malloc(sizeof(t_particle_list));

    rpg->particles->attack = malloc(sizeof(t_particle));
    rpg->particles->attack->object = create_object(
        "ressources/particles/attack.png", (sfVector2f){0, 0},
        (sfIntRect){0, 0, 192, 192});
    rpg->particles->attack->clk = sfClock_create();
    rpg->particles->attack->is_rendered = FALSE;
}

void init_all(t_rpg *rpg)
{
    init_character(rpg);
    init_struct_loop(rpg);
    init_hud(rpg);
    init_audio(rpg);
    init_hud_pause(rpg);
    init_quests(rpg);
    init_npc(rpg);
    init_mobs(rpg);
    init_particles(rpg);
}

t_rpg *init_struct_game()
{
    t_rpg *res = malloc(sizeof(t_rpg));

    res->gamestate = MENULOOP;
    res->character = NULL;
    res->clickstate = CLICK_RELEASED;
    return res;
}