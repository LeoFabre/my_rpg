/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "my.h"
#include "rpg.h"

char *get_potion_name(int slotid)
{
    char *result = malloc(sizeof(char) * 30);

    if (slotid == PBLUE)
        return (my_strcpy(result, "Blue Potion"));
    if (slotid == PDARKGREEN)
        return (my_strcpy(result, "Dark Green Potion"));
    if (slotid == PGREEN)
        return (my_strcpy(result, "Green Potion"));
    if (slotid == PPURPLE)
        return (my_strcpy(result, "Purple Potion"));
    if (slotid == PRED)
        return (my_strcpy(result, "Red Potion"));
    if (slotid == PWINERED)
        return (my_strcpy(result, "Winered Potion"));
    if (slotid == PYELLOW)
        return (my_strcpy(result, "Yellow Potion"));
    else
        return (my_strcpy(result, "Aucun"));
}

char *get_item_name(int slotid)
{
    char *result = malloc(sizeof(char) * 30);

    switch (slotid) {
    case 1:
        my_strcpy(result, "Sword"); break;
    case 2:
        my_strcpy(result, "Heal"); break;
    case 3:
        my_strcpy(result, "Key"); break;
    default:
        my_strcpy(result, "Aucun"); break;
    }
    if (my_strcmp(result, "Aucun") != 0)
        return (result);
    else {
        my_strcpy(result, get_potion_name(slotid));
        return (result);
    }
}