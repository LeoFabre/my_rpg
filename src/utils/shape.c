/*
** EPITECH PROJECT, 2024
** MUL_my_defender_2019
** File description:
** Created by Achille Bourgault
*/

#include <SFML//Graphics.h>

sfRectangleShape *create_rec_shape(int x, int y, int filled, sfColor color)
{
    sfRectangleShape *result = sfRectangleShape_create();
    sfVector2f size;

    size.x = (float)x;
    size.y = (float)y;
    sfRectangleShape_setSize(result, size);
    if (filled != 0)
        sfRectangleShape_setFillColor(result, color);
    return (result);
}

sfCircleShape *create_circle_shape(int size, int filled, sfColor color)
{
    sfCircleShape *result;

    result = sfCircleShape_create();
    sfCircleShape_setRadius(result, (float)size);
    if (filled != 0)
        sfCircleShape_setFillColor(result, color);
    return (result);
}