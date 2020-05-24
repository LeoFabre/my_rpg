/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/
#include "rpg.h"

char *get_transform(int pow)
{
    char *res = malloc(sizeof(char) * 3);

    res[0] = '-';
    res[1] = ' ';
    res[2] = '\0';
    res = my_strcat(res, my_itoa(pow));
    return (res);
}

void do_crit(t_rpg *rpg)
{
    sfSound_setPitch(rpg->audio->fight_sound, 505);
    sfSound_play(rpg->audio->fight_sound);
    sfSound_setPitch(rpg->audio->fight_sound, 1);
    my_printf("CRITICAL ! \n");
    add_xp(rpg, 30);
}

void attack(t_rpg *rpg)
{
    int attack_force = (int)(
        sfSprite_getTextureRect(rpg->fight->progress->spr).width / 7.8);
    char *res = get_transform(attack_force);

    if (attack_force >= 99) {
        do_crit(rpg);
        attack_force = 100;
    }
    sfSound_play(rpg->audio->fight_sound);
    my_printf("POW ! %i\n", attack_force);
    spawn_attack_particle(rpg, rpg->fight->opponent->sprite);
    sfText_setString(rpg->hud->pnj_details[3], res);
    rpg->hud->details_pv = 70;
    rpg->character->quests->stats->damage += attack_force;
    rpg->fight->opponent->health -= attack_force;
    rpg->fight->is_player_turn = FALSE;
    sfClock_restart(rpg->fight->clk);
}

void mob_attack(t_rpg *rpg)
{
    sfTime timer = sfClock_getElapsedTime(rpg->fight->clk);
    float seconds = (float)timer.microseconds / 1000000.0f;
    static int has_attacked = FALSE;
    int attack_power = rand() % (10 + 10 * (rpg->character->level - 1)) + 1;
    char *res = get_transform(attack_power);

    if (seconds < 1)
        return;
    if (seconds >= 1 && has_attacked == FALSE) {
        sfText_setString(rpg->hud->pnj_details[2], res);
        rpg->hud->details_mob_pv = 70;
        sfSound_play(rpg->audio->fight_sound);
        rpg->character->health -= attack_power;
        spawn_attack_particle(rpg, rpg->character->obj->sprite);
        has_attacked = TRUE;
    }
    if (seconds >= 2) {
        rpg->fight->is_player_turn = TRUE;
        has_attacked = FALSE;
        sfClock_restart(rpg->fight->clk);
    }
}