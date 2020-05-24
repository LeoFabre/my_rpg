/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/

#include "rpg.h"

void give_popo(t_rpg *rpg, int fight_count)
{
    switch (fight_count) {
    case 1:
        add_to_inventory(rpg, 5);
        add_xp(rpg, 75);
        break;
    case 3:
        add_to_inventory(rpg, 8);
        add_xp(rpg, 75);
        break;
    case 5:
        add_to_inventory(rpg, 10);
        add_xp(rpg, 75);
        break;
    case 7:
        add_to_inventory(rpg, 9);
        add_xp(rpg, 75);
        break;
    }
}

void end_fight(t_rpg *rpg)
{
    static int fight_count = 0;

    rpg->fight->opponent->health = 0;
    rpg->fight->opponent = NULL;
    add_xp(rpg, 75);
    rpg->character->quests->stats->kill++;
    rpg->gamestate = GAMELOOP;
    give_popo(rpg, fight_count);
    fight_count++;
}

void fightloop_2(t_rpg *rpg)
{
    display_attack_particle(rpg);
    draw_text_levitate(rpg, rpg->hud->pnj_details[TEXT_MPV],
        &rpg->hud->details_mob_pv, rpg->hud->clock[2]);
    draw_text_levitate_mob(rpg, rpg->hud->pnj_details[3], &rpg->hud->details_pv,
        rpg->hud->clock[3]);
    display_inventory(rpg);
    sfRenderWindow_display(rpg->window);
}

void fightloop(t_rpg *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    display_backgroud(rpg);
    display_items(rpg);
    display_mobs(rpg);
    display_character(rpg);
    display_hud(rpg);
    if (rpg->fight->is_player_turn == TRUE) {
        update_progression(rpg);
        draw_progress_bar(rpg);
    } else {
        if (rpg->fight->opponent->health <= 0) {
            end_fight(rpg);
            return;
        } else if (rpg->character->health <= 0) {
            rpg->gamestate = GAMEOVERLOOP;
            return;
        }
        mob_attack(rpg);
    }
    fightloop_2(rpg);
}

void analyze_fight_events(t_rpg *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue &&
        rpg->fight->pressing_atk == FALSE &&
        rpg->fight->is_player_turn == TRUE) {
        attack(rpg);
        rpg->fight->pressing_atk = TRUE;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse)
        rpg->fight->pressing_atk = FALSE;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        rpg->old_gamestate = FIGHTLOOP;
        rpg->gamestate = PAUSELOOP;
    }
}