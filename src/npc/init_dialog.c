/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_dialog
*/

#include "rpg.h"

sfText **shopkeeper_init_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 5);
    npc_dialog[0] = create_text("Welcome to my shop traveler !", font, sfBlack,
    22);
    npc_dialog[1] = create_text("I would like to spread a covid-19 cure "
    ",\nbut some evil demons stole the potions\n"
    "which are needed by the professor to create one.",
    font, sfBlack, 22);
    npc_dialog[2] = create_text("Find the potions, destroy all those vilains"
    ",\nand make the covid-19 cure a reality thanks to the Raoult Professor.",
    font, sfBlack, 22);
    npc_dialog[3] = create_text("You need to catch them!\n", font, sfBlack, 22);
    npc_dialog[4] = NULL;
    return (npc_dialog);
}

sfText **enzo_init_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 4);
    npc_dialog[0] = create_text("You finally found me !", font, sfBlack, 22);
    npc_dialog[1] = create_text("I've been able to kill some of them,\n"
    "here, take my potion and give it to Raoult, he'll know what to do !",
    font, sfBlack, 22);
    npc_dialog[2] = create_text("You should meet Lea, she's leaving on the\n"
    "other side of the river.", font, sfBlack, 22);
    npc_dialog[3] = NULL;
    return (npc_dialog);
}

sfText **lea_init_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 4);
    npc_dialog[0] = create_text("Owh, you found me !", font, sfBlack, 22);
    npc_dialog[1] = create_text("I've been able to escape from them for now,\n"
    "here, take it and give it to Raoult, it's gonna help.",
    font, sfBlack, 22);
    npc_dialog[2] = create_text("Come on, run straight to the north !\n"
    "I'm gonna try to catch them...", font, sfBlack, 22);
    npc_dialog[3] = NULL;
    return (npc_dialog);
}

sfText **raoult_init_dialog(sfFont *font)
{
    sfText **npc_dialog = malloc(sizeof(sfText *) * 5);
    npc_dialog[0] = create_text("Hello dear Wanderer,", font, sfBlack, 22);
    npc_dialog[1] = create_text("I hope you brought all my potions with you !\n"
    "You got them all ? Nice !\n"
    "I hope you weren't expecting my gratitude, I'm gonna burn this.",
    font, sfBlack, 22);
    npc_dialog[2] = create_text("What ? No it wasn't about the covid cure..\n"
    "I found something, it's called chloroquine, i've tested it on monkeys,\n"
    "I already sent some tests for Asia.", font,
    sfBlack, 22);
    npc_dialog[3] = create_text("Well it's fine, I'm going back to work\n"
    "You can leave, no fairy tale or princess to kiss here.",
    font, sfBlack, 22);
    npc_dialog[4] = NULL;
    return (npc_dialog);
}