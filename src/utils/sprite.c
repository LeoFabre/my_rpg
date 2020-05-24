/*
** EPITECH PROJECT, 2024
** MUL_my_defender_2019
** File description:
** Created by Achille Bourgault
*/

#include <SFML/Graphics.h>
#include "my.h"

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    if (!texture)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}