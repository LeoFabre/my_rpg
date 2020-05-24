/*
** EPITECH PROJECT, 2024
** MUL_my_defender_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

sfMusic *create_music(char *filepath, int play, int repeated)
{
    sfMusic *music;

    music = sfMusic_createFromFile(filepath);
    if (!music)
        return (NULL);
    if (repeated > 0)
        sfMusic_setLoop(music, sfTrue);
    if (play > 0)
        sfMusic_play(music);
    return (music);
}

sfSound *create_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);

    sfSound_setBuffer(sound, buffer);
    if (!sound)
        return (NULL);
    else
        return (sound);
}