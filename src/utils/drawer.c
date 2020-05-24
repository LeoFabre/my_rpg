/*
** EPITECH PROJECT, 2024
** MUL_my_defender_2019
** File description:
** Created by Achille Bourgault
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../include/my.h"

void drawer(sfRenderWindow *window, sfSprite *sprite, int pos_x, int pos_y)
{
    sfVector2f pos;

    if (sprite == NULL)
        my_putstr("Error: Bad filepath [SPRITE]\n");
    else {
        if (pos_x != -42 || pos_y != -42) {
            pos.x = (float)pos_x;
            pos.y = (float)pos_y;
            sfSprite_setPosition(sprite, pos);
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

void draw_text(sfRenderWindow *window, sfText *new_text, int pos_x, int pos_y)
{
    sfVector2f pos;

    pos.x = (float)pos_x;
    pos.y = (float)pos_y;
    sfText_setPosition(new_text, pos);
    sfRenderWindow_drawText(window, new_text, NULL);
}

void draw_shape(sfRenderWindow *window, sfRectangleShape *shape, int pos_x,
    int pos_y)
{
    sfVector2f pos;

    if (pos_x != -42 || pos_y != -42) {
        pos.x = (float)pos_x;
        pos.y = (float)pos_y;
        sfRectangleShape_setPosition(shape, pos);
    }
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
}

void draw_circle(sfRenderWindow *window, sfCircleShape *shape, int pos_x,
    int pos_y)
{
    sfVector2f pos;

    if (pos_x != -42 || pos_y != -42) {
        pos.x = (float)pos_x;
        pos.y = (float)pos_y;
        sfCircleShape_setPosition(shape, pos);
    }
    sfRenderWindow_drawCircleShape(window, shape, NULL);
}