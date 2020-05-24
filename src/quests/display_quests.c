/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Achille Bourgault
*/

#include "my.h"
#include "rpg.h"

void open_qbook(t_rpg *rpg)
{
    sfSound_play(rpg->character->quests->sound);
    rpg->character->quests->is_open = 1;
}

void close_qbook(t_rpg *rpg)
{
    rpg->character->quests->is_open = 0;
}

void stats2(t_rpg *rpg)
{
    char *xp = my_strdup(my_itoa(rpg->character->level));

    sfText_setString(rpg->character->quests->stats->text[6], xp);
    draw_text(rpg->window, rpg->character->quests->stats->text[5],
        (int)(sfRenderWindow_getSize(rpg->window).x / 2) + 110,
        (int)(sfRenderWindow_getSize(rpg->window).y / 2) - 15);
    draw_text(rpg->window, rpg->character->quests->stats->text[6],
        (int)(sfRenderWindow_getSize(rpg->window).x / 2) + 175,
        (int)(sfRenderWindow_getSize(rpg->window).y / 2) - 15);
}

void display_stats(t_rpg *rpg)
{
    char *kill = my_strdup(my_itoa(rpg->character->quests->stats->kill));
    char *damage = my_strdup(my_itoa(rpg->character->quests->stats->damage));
    sfVector2u winsize = sfRenderWindow_getSize(rpg->window);

    sfText_setString(rpg->character->quests->stats->text[2], kill);
    sfText_setString(rpg->character->quests->stats->text[4], damage);
    draw_text(rpg->window, rpg->character->quests->stats->text[0],
        (int)(winsize.x / 2) + 230, (int)(winsize.y / 2) - 200);
    draw_text(rpg->window, rpg->character->quests->stats->text[1],
        (int)(winsize.x / 2) + 110, (int)(winsize.y / 2) - 85);
    draw_text(rpg->window, rpg->character->quests->stats->text[2],
        (int)(winsize.x / 2) + 175, (int)(winsize.y / 2) - 85);
    draw_text(rpg->window, rpg->character->quests->stats->text[3],
        (int)(winsize.x / 2) + 110, (int)(winsize.y / 2) - 50);
    draw_text(rpg->window, rpg->character->quests->stats->text[4],
        (int)(winsize.x / 2) + 205, (int)(winsize.y / 2) - 50);
    stats2(rpg);
}

void display_quests(t_rpg *rpg)
{
    char *objective = my_strdup(my_itoa(rpg->character->quests->collect));
    sfVector2u winsize = sfRenderWindow_getSize(rpg->window);

    objective = my_strcat(objective, "/7");
    if (rpg->character->quests->is_open == 1) {
        sfText_setString(rpg->character->quests->text[2], objective);
        sfSprite_setScale(rpg->character->quests->sprite_book,
            (sfVector2f){0.5, 0.5});
        drawer(rpg->window, rpg->character->quests->sprite_book,
            (int)(winsize.x / 2) - 500, (int)(winsize.y / 2) - 350);
        draw_text(rpg->window, rpg->character->quests->text[0],
            (int)(winsize.x / 2) - 170, (int)(winsize.y / 2) - 200);
        draw_text(rpg->window, rpg->character->quests->text[1],
            (int)(winsize.x / 2) - 300, (int)(winsize.y / 2) - 150);
        draw_text(rpg->window, rpg->character->quests->text[2],
            (int)(winsize.x / 2) - 145, (int)(winsize.y / 2) + 230);
        display_stats(rpg);
    }
}