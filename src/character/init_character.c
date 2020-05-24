/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#include "rpg.h"

void init_moves(t_rpg *rpg)
{
    char *path = NULL;

    rpg->character->moves = malloc(sizeof(sfImage **) * 4);
    for (int line = 0; line <= 2; ++line) {
        rpg->character->moves[line] = malloc(sizeof(sfImage *) * 4);
        for (int col = 0; col <= 2; ++col) {
            path = my_strcat(my_strcat("ressources/map/moves/",
                my_strcat(my_itoa(line), my_itoa(col))), ".png");
            my_printf("loading %s...\n", path);
            rpg->character->moves[line][col] = sfImage_createFromFile(path);
        }
        rpg->character->moves[line][3] = NULL;
    }
    rpg->character->moves[3] = NULL;
}

void init_character(t_rpg *rpg)
{
    rpg->character = malloc(sizeof(t_character));
    rpg->character->level = 1;
    rpg->character->health = 100;
    rpg->character->xp = 0;
    rpg->character->move_state = IDLE;
    rpg->character->obj = create_object("ressources/character.png",
        (sfVector2f){770, 570}, (sfIntRect){0, 0, 46, 60});
    sfSprite_setScale(rpg->character->obj->sprite,
        (sfVector2f){SCALEPERSO, SCALEPERSO});
    rpg->character->clkanim = sfClock_create();
    rpg->character->current_chunk = malloc(sizeof(int) * 2);
    rpg->character->current_chunk[CHUNK_Y] = 2;
    rpg->character->current_chunk[CHUNK_X] = 0;
    init_moves(rpg);
    init_inventory(rpg);
}