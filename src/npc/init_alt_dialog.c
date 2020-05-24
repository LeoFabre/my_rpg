/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_alt_dialog
*/

#include "rpg.h"

sfText **shopkeeper_init_alt_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 5);
    npc_dialog[0] = create_text("Welcome back to my shop traveler !", font,
        sfBlack, 22);
    npc_dialog[1] = create_text("I would like to spread a covid-19 cure "
    ",\nbut some evil demons stole the potions\n"
    "which are needed by the professor to create one.",
        font, sfBlack, 22);
    npc_dialog[2] = create_text("Find the potions, destroy all those vilains"
    ",\nand make the covid-19 cure a reality thanks to the"
    "Raoult Professor.",
        font, sfBlack, 22);
    npc_dialog[3] = create_text("You need to catch them!\n", font, sfBlack, 22);
    npc_dialog[4] = NULL;
    return (npc_dialog);
}

sfText **enzo_init_alt_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 4);
    npc_dialog[0] = create_text("You should meet Lea, she's leaving on the\n"
                                "other side of the river.", font, sfBlack, 22);
    npc_dialog[1] = create_text("Come on !", font, sfBlack, 22);
    npc_dialog[2] = create_text("Go fast now !", font, sfBlack, 22);
    npc_dialog[3] = NULL;
    return (npc_dialog);
}

sfText **lea_init_alt_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 4);
    npc_dialog[0] = create_text("Come on, run straight to the north !\n"
                                "I'm gonna try to catch them...", font, sfBlack,
        22);
    npc_dialog[1] = create_text("Let's go !", font, sfBlack, 22);
    npc_dialog[2] = create_text("Just go fast !", font, sfBlack, 22);
    npc_dialog[3] = NULL;
    return (npc_dialog);
}

sfText **raoult_init_alt_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 5);
    npc_dialog[0] = create_text(
        "You have nothing dude, where are my potions ?!", font, sfBlack,
        22);
    npc_dialog[1] = create_text("For real !", font, sfBlack, 22);
    npc_dialog[2] = create_text("Byebye.", font, sfBlack, 22);
    npc_dialog[3] = create_text("Get out of my laboratory !", font, sfBlack,
        22);
    npc_dialog[4] = NULL;
    return (npc_dialog);
}