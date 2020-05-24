/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/
#include "rpg.h"

void loop(t_rpg *rpg, void ((*scenes[5])(t_rpg *)),
    void ((*events[5])(t_rpg *)))
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            (events[rpg->gamestate])(rpg);
        }
        scene_manager(rpg, scenes);
    }
}

void game(t_rpg *rpg)
{
    sfVideoMode video_mode = {1536, 768, 32};
    void ((*scenes[5])(t_rpg *)) = {&menuloop, &gameloop, &fightloop,
        &pauseloop, &gameoverloop};
    void ((*events[5])(t_rpg *)) = {&analyse_menu_events, &gameloop_events,
        &analyze_fight_events, &analyse_pausemenu_events,
        &analyse_gameover_events};

    rpg->window = sfRenderWindow_create(video_mode, "My_RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    init_menu(rpg);
    init_fight(rpg);
    loop(rpg, scenes, events);
    destroy_all(rpg);
}