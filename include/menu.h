/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Leo Fabre
*/
#ifndef MUL_MY_RPG_2019_MENU_H
#define MUL_MY_RPG_2019_MENU_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/Types.h>

typedef struct s_button t_button;
typedef struct s_rpg t_rpg;
typedef struct s_obj t_obj;

float center_y_btn(t_rpg *rpg, t_button *btn, float div_offset);
float center_x_btn(t_rpg *rpg, t_button *btn);
void animate_btns(t_rpg *rpg);
void animate_btn(t_rpg *mydefender, t_button *btn);
void make_btn_rect(t_button btn);
void init_menu(t_rpg *rpg);
void manage_menu_click(t_rpg *rpg);
void manage_menu_release_click(t_rpg *rpg);
void move_btns(t_rpg *rpg);
void analyse_menu_events(t_rpg *rpg);
void init_mainlogo_pos(t_rpg *rpg);
void init_btns_rects(t_rpg *rpg);
void animate_btns_pause(t_rpg *rpg);
void animate_btn_pause(t_rpg *mydefender, t_button *btn);
void init_btns_rects_pause(t_rpg *rpg);
void make_btn_rect_pause(t_button btn);
void manage_pausemenu_click(t_rpg *rpg);
void manage_pausemenu_release_click(t_rpg *rpg);
void analyse_pausemenu_events(t_rpg *rpg);
void init_logo_pos(t_rpg *rpg, t_obj *logo);
void manage_gameover_click(t_rpg *rpg);
void manage_gameover_release_click(t_rpg *rpg);
void make_btn_rect_gameover(t_button btn);
void init_btns_rects_gameover(t_rpg *rpg);
void animate_btns_gameover(t_rpg *rpg);

#endif //MUL_MY_RPG_2019_MENU_H
