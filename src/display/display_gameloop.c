/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void display_mobs(t_rpg *rpg)
{
    t_mob *tmp = rpg->gameloop->moblist->first;

    for (; tmp != NULL; tmp = tmp->next) {
        if (rpg->gameloop->camera_mouv == FALSE && tmp->health > 0 &&
            rpg->character->current_chunk[CHUNK_Y] == tmp->chunk[CHUNK_Y] &&
            rpg->character->current_chunk[CHUNK_X] == tmp->chunk[CHUNK_X]) {
            sfRenderWindow_drawSprite(rpg->window, tmp->sprite, NULL);
        }
    }
    animate_sprite_rat(rpg);
    animate_bat(rpg);
    animate_sprite_bat(rpg);
}

void display_items(t_rpg *rpg)
{
    t_elem *tmp = rpg->gameloop->list_items->first;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->printable == 1) {
            sfSprite_setScale(tmp->object->sprite, (sfVector2f){0.5, 0.5});
            sfRenderWindow_drawSprite(rpg->window, tmp->object->sprite, NULL);
        }
    }
    anim_items(rpg);
}

void display_backgroud(t_rpg *rpg)
{
    for (int i = 0; rpg->gameloop->bg_bf_char[i]; i++)
        sfRenderWindow_drawSprite(rpg->window,
            rpg->gameloop->bg_bf_char[i]->sprite, NULL);
    display_character(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->gameloop->houses_up->sprite,
        NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->gameloop->fence->sprite, NULL);

}

void play_sound_run(t_rpg *rpg)
{
    if (rpg->gamestate != FIGHTLOOP && rpg->audio->run == 1 &&
        rpg->audio->update == 1) {
        sfMusic_play(rpg->audio->run_sound);
        rpg->audio->update = 1;
    } else if ((rpg->audio->run == 0 && rpg->audio->update == 1) ||
        rpg->gamestate == FIGHTLOOP) {
        sfMusic_stop(rpg->audio->run_sound);
        rpg->audio->update = 1;
    }
}

void display_loop(t_rpg *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    play_sound_run(rpg);
    display_backgroud(rpg);
    display_items(rpg);
    display_mobs(rpg);
    display_inventory(rpg);
    display_hud(rpg);
    display_quests(rpg);
    display_npc_dialog(rpg);
    display_attack_particle(rpg);
    sfRenderWindow_display(rpg->window);
}