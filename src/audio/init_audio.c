/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void set_music(t_rpg *rpg, int musicid, int play)
{
    if (rpg->audio->play == 1) {
        sfMusic_stop(rpg->audio->current);
        rpg->audio->play = 0;
    }
    rpg->audio->current = rpg->audio->music[musicid];
    if (play == 1) {
        sfMusic_play(rpg->audio->current);
        rpg->audio->play = 1;
    }
}

void init_audio(t_rpg *rpg)
{
    rpg->audio = malloc(sizeof(t_audio));
    rpg->audio->music = malloc(sizeof(sfMusic *) * 2);
    rpg->audio->play = 0;
    rpg->audio->run = 0;
    rpg->audio->fight_sound = create_sound("ressources/sounds/fight.ogg");
    rpg->audio->update = 0;
    rpg->audio->run_sound = create_music("ressources/sounds/run.ogg", 0, 1);
    rpg->audio->music[1] = create_music("ressources/sounds/game.ogg", 0, 1);
    rpg->character->inventory->sounds = malloc(sizeof(sfSound *) * 2);
    rpg->character->inventory->sounds[0] = create_sound(
    "ressources/sounds/open_chest.ogg");
    rpg->character->inventory->sounds[1] = create_sound(
    "ressources/sounds/close_chest.ogg");
    sfSound_setVolume(rpg->character->inventory->sounds[0], 50);
    sfSound_setVolume(rpg->character->inventory->sounds[1], 50);
    sfMusic_setVolume(rpg->audio->music[1], 50);
}