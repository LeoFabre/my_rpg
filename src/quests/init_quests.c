/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "rpg.h"

void init_stats(t_rpg *rpg, sfFont *font)
{
    rpg->character->quests->stats = malloc(sizeof(t_stats));
    rpg->character->quests->stats->text = malloc(sizeof(sfText *) * 7);
    rpg->character->quests->stats->damage = 0;
    rpg->character->quests->stats->kill = 0;
    rpg->character->quests->stats->text[0] = create_text("STATS", font, sfBlack,
        40);
    rpg->character->quests->stats->text[1] = create_text("KILLS: ", font,
        sfBlack, 25);
    rpg->character->quests->stats->text[2] = create_text("{KILLS} ", font,
        sfColor_fromRGB(200, 50, 50), 25);
    rpg->character->quests->stats->text[3] = create_text("DAMAGES: ", font,
        sfBlack, 25);
    rpg->character->quests->stats->text[4] = create_text("{DAMAGES} ", font,
        sfColor_fromRGB(200, 50, 50), 25);
    rpg->character->quests->stats->text[5] = create_text("LEVEL: ", font,
        sfBlack, 25);
    rpg->character->quests->stats->text[6] = create_text("{LEVEL}", font,
        sfColor_fromRGB(200, 50, 50), 25);;
    rpg->character->quests->sound = create_sound(
        "ressources/sounds/quest_open.ogg");
}

void init_quests(t_rpg *rpg)
{
    sfFont *font = sfFont_createFromFile("ressources/fonts/new_itemfont.ttf");
    rpg->character->quests = malloc(sizeof(t_quests));
    rpg->character->quests->sprite_book = create_sprite(
        "ressources/hud/quest.png");
    rpg->character->quests->status = 1;
    rpg->character->quests->collect = 0;
    rpg->character->quests->text = malloc(sizeof(sfText *) * 3);
    rpg->character->quests->is_pressed = 0;
    rpg->character->quests->is_open = 0;
    rpg->character->quests->text[0] = create_text("QUEST", font, sfBlack, 40);
    rpg->character->quests->text[1] = create_text("\n"
    "Hey Jack.\nHave you heard of coronavirus?\n"
    "This virus is killing everyone!\n\nAn old man says that with 7 potions\n"
    "we could create a vaccine.\nCould you do it?\n\n"
    "Oh and be careful it seems\nthat the virus has transformed\n"
    "some villagers into monsters..",
    font, sfBlack, 25);
    rpg->character->quests->text[2] = create_text("0/8", font,
        sfColor_fromRGB(200, 50, 50), 25);
    init_stats(rpg, font);
}

void destroy_quests(t_rpg *rpg)
{
    sfSprite_destroy(rpg->character->quests->sprite_book);
    sfText_destroy(rpg->character->quests->text[0]);
    sfText_destroy(rpg->character->quests->text[1]);
    sfText_destroy(rpg->character->quests->text[2]);
    sfText_destroy(rpg->character->quests->stats->text[0]);
    sfText_destroy(rpg->character->quests->stats->text[1]);
    sfText_destroy(rpg->character->quests->stats->text[2]);
    sfText_destroy(rpg->character->quests->stats->text[3]);
    sfText_destroy(rpg->character->quests->stats->text[4]);
    sfText_destroy(rpg->character->quests->stats->text[5]);
    sfText_destroy(rpg->character->quests->stats->text[6]);
    sfSound_destroy(rpg->character->quests->sound);
}