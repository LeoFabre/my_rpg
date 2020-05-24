/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** Created by Enzo Ventura
*/

#ifndef MUL_MY_RPG_2019_RPG_H
#define MUL_MY_RPG_2019_RPG_H

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include "my.h"
#include "linkedlists.h"
#include "menu.h"

#define WIDTHMAP 256
#define HEIGHTMAP 512

#define BTN_IDLE 1
#define BTN_HOVER 2
#define BTN_PRESSED 3

#define TEXT_XP 0
#define TEXT_PPV 1
#define TEXT_MPV 2

#define STARTBTN 0
#define QUITBTN 1
#define RETRYBTN 2
#define MENUBTN 3
#define RESUMEBTN 4

#define CURVEUP 1
#define CURVEDOWN 0

#define TRUE 1
#define FALSE 0

#define CHUNK_Y 0
#define CHUNK_X 1

#define SCALEPERSO 1.2
#define CLICK_PRESSED 1
#define CLICK_RELEASED 0
#define SPEEDCHAR 6
#define IDLE -1
#define DOWN 0
#define RIGHT 1
#define LEFT 2
#define UP 3

#define MENULOOP 0
#define GAMELOOP 1
#define FIGHTLOOP 2
#define PAUSELOOP 3
#define GAMEOVERLOOP 4

#define CAMUP 1
#define CAMDOWN 2
#define CAMRIGHT 3
#define CAMLEFT 4
#define CAMIDLE 0
#define CAMCLK 0.001

#define PBLUE 4
#define PDARKGREEN 5
#define PGREEN 6
#define PPURPLE 7
#define PRED 8
#define PWINERED 9
#define PYELLOW 10

#define RAT 0
#define BAT 1

#define ANIMBAT 0
#define SPBAT 1
#define SPRAT 1

typedef struct s_obj t_obj;

typedef struct s_inv {
    int is_open;
    int is_pressed;
    int *inventory;
    int new_item_delay;
    sfSprite *new_item;
    sfSprite *inv_sprite;
    sfSprite **items;
    sfSound **sounds;
    sfText *new_itemtxt;
} t_inv;

typedef struct s_hud {
    sfClock **clock;
    sfSprite *bar_sprite;
    sfSprite **heart_sprite;
    sfSprite **xp_bar;
    sfRectangleShape **btn;
    sfText **btn_label;
    sfSound *xp_sound;
    int details;
    int details_mob_pv;
    int details_pv;
    sfText **pnj_details;
    int pause;
    int p_is_pressed;
} t_hud;

typedef struct s_button {
    sfTexture *texture;
    sfSprite *sprite;
    int state;
} t_button;

typedef struct s_menuobjs {
    t_obj *bg;
    t_obj *mainlogo;
    t_obj *pauselogo;
    t_obj *gameoverlogo;
    t_button *btns;
} t_menuobjs;

typedef struct s_game_item {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int id;
} t_game_item;

typedef struct s_mob t_mob;

typedef struct s_mob {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int health;
    t_mob *next;
    t_mob *prev;
    int chunk[2];
    int id;
} t_mob;

typedef struct s_moblist {
    t_mob *first;
    t_mob *last;
    sfClock **clk_bat;
    sfClock **clk_rat;
} t_moblist;

typedef struct s_game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} t_game_object;

typedef struct s_obj {
    sfSprite *spr;
    sfTexture *tex;
} t_obj;

typedef struct s_stats {
    int kill;
    int damage;
    sfText **text;
    sfSprite **icon;
} t_stats;

typedef struct s_quests {
    int is_open;
    int is_pressed;
    int status;
    int collect;
    sfSound *sound;
    sfSprite *sprite_book;
    sfText **text;
    t_stats *stats;
} t_quests;

typedef struct s_character {
    t_game_object *obj;
    sfClock *clkanim;
    sfImage ***moves;
    t_inv *inventory;
    t_quests *quests;
    int *current_chunk;
    int move_state;
    int health;
    int xp;
    int level;
} t_character;

typedef struct s_menuobjs t_menuobjs;

typedef struct s_game_loop {
    t_list *list_items;
    t_moblist *moblist;
    sfClock *anim_items;
    sfClock *camera_clk;
    t_game_object **bg_bf_char;
    t_game_object *houses_up;
    t_game_object *fence;
    int camera_mouv;
} t_gameloop;

typedef struct s_fight {
    t_obj *progressbar;
    t_obj *progress;
    int pressing_atk;
    int is_player_turn;
    t_mob *opponent;
    sfClock *clk;
} t_fight;

typedef struct s_npc {
    sfText *name;
    int item_id;
    int xp_amount;
    sfText **quest_dialog;
    sfText **quest_alt_dialog;
    sfVector2f pos;
    sfVector2i chunk;
} t_npc;

typedef struct s_npc_manager {
    sfSprite *dialog_sprite;
    sfBool is_in_dialog;
    int *npc_status;
    t_npc *current_npc;
    sfText **current_dialog;
    sfText *dialog_hover;
    int dialog_pos;
    t_npc **npc;
    int isKeyDown;
    int should_display_hover;
} t_npc_manager;

typedef struct s_audio {
    sfMusic **music;
    sfSound *fight_sound;
    sfSound *start_sound;
    int play;
    int update;
    int run;
    sfMusic *run_sound;
    sfMusic *current;
} t_audio;

typedef struct s_particle {
    t_game_object *object;
    sfClock *clk;
    int is_rendered;
} t_particle;

typedef struct s_particle_list {
    t_particle *attack;
} t_particle_list;

typedef struct s_rpg {
    sfRenderWindow *window;
    sfEvent event;
    t_character *character;
    t_menuobjs *menu;
    t_gameloop *gameloop;
    t_fight *fight;
    t_hud *hud;
    t_audio *audio;
    t_particle_list *particles;
    t_npc_manager *npc_manager;
    int gamestate;
    int old_gamestate;
    int clickstate;
} t_rpg;

//destroy
void destroy_all(t_rpg *rpg);
void destroy_quests(t_rpg *rpg);
void destroy_inventory(t_rpg *rpg);
void destroy_npc(t_rpg *rpg);

//audio
void init_audio(t_rpg *rpg);
void play_music(t_rpg *rpg);
void set_music(t_rpg *rpg, int musicid, int play);

//inventory
void init_inventory(t_rpg *rpg);
int add_to_inventory(t_rpg *rpg, int itemid);
int remove_to_inventory(t_rpg *rpg, int slotid);
char *get_item_name(int slotid);
void open_inventory(t_rpg *rpg);
void close_inventory(t_rpg *rpg);
void draw_inventory(t_rpg *rpg);
void display_inventory(t_rpg *rpg);
int check_key(t_rpg *rpg);

//linked Lists
void free_list(t_list *list);
void rm_last(t_list *list);
void rm_first(t_list *list);
void create_and_add_to_start(t_list *list, char *path, int id, sfVector2f pos);
void create_item(t_list *list, char *path, int id, sfVector2f pos);
void create_item_not_dropped(t_list *list, char *path, int id, sfVector2f pos);
int list_len(t_list *list);
t_list *init_list(void);
void add_elem_to_end(t_elem *new, t_rpg *rpg);
void add_elem_to_start(t_elem *new, t_rpg *rpg);
void do_pass(t_rpg *rpg, int len, t_elem *current);
void swap_with_next(t_elem *target, t_rpg *rpg);
int swap_first_last(t_elem *target, t_rpg *rpg);
void debug_print_moblist(t_moblist *list);

//init
t_rpg *init_struct_game();
void init_all(t_rpg *rpg);
void create_background(t_rpg *rpg);
void init_fight(t_rpg *rpg);
void init_items_map(t_rpg *rpg);

//quests
void init_quests(t_rpg *rpg);
void display_quests(t_rpg *rpg);
void open_qbook(t_rpg *rpg);
void close_qbook(t_rpg *rpg);

//hud
void init_hud(t_rpg *rpg);
void init_hud_pause(t_rpg *rpg);
void display_hud(t_rpg *rpg);
void display_pause(t_rpg *rpg);
void open_pause(t_rpg *rpg);
void close_pause(t_rpg *rpg);
void gameoverloop(t_rpg *rpg);
void display_gameover(t_rpg *rpg);

//xp
void add_xp(t_rpg *rpg, int xp);
void update_xp(t_rpg *rpg);

//create game object
t_game_object *create_object(const char *path_sp, sfVector2f pos,
    sfIntRect rect);
t_obj *make_obj(const char *filepath);
void destroy_obj(t_obj *obj);

//game
void game(t_rpg *rpg);

void loop(t_rpg *rpg, void ((*array[5])(t_rpg *)),
    void ((*events[5])(t_rpg *)));

//scenes
void scene_manager(t_rpg *rpg, void ((*array[5])(t_rpg *)));

void menuloop(t_rpg *rpg);
void gameloop(t_rpg *rpg);
void pauseloop(t_rpg *rpg);

//events
void gameloop_events(t_rpg *rpg);
void home_events(t_rpg *rpg);
void analyze_fight_events(t_rpg *rpg);
void analyse_pausemenu_events(t_rpg *rpg);
void analyse_gameover_events(t_rpg *rpg);

//drawer.c
void draw_circle(sfRenderWindow *window, sfCircleShape *shape, int pos_x,
    int pos_y);
void draw_shape(sfRenderWindow *window, sfRectangleShape *shape, int pos_x,
    int pos_y);
void draw_text(sfRenderWindow *window, sfText *new_text, int pos_x, int pos_y);
void drawer(sfRenderWindow *window, sfSprite *sprite, int pos_x, int pos_y);

//music
sfMusic *create_music(char *filepath, int play, int repeated);
sfSound *create_sound(char *filepath);

//shape
sfCircleShape *create_circle_shape(int size, int filled, sfColor color);
sfRectangleShape *create_rec_shape(int x, int y, int filled, sfColor color);

//sprite
sfSprite *create_sprite(char *filepath);

//text
sfText *create_text(const char *text, sfFont *font, sfColor color, int height);
void draw_text_levitate(t_rpg *rpg, sfText *text, int *details, sfClock *clock);
void draw_text_levitate_mob(t_rpg *rpg, sfText *text, int *details,
    sfClock *clock);

//hitbox
int cur_on_hitbox(t_rpg *mydefender, sfSprite *sprite);
//display
void display_loop(t_rpg *rpg);

//character
void display_character(t_rpg *rpg);
void init_character(t_rpg *rpg);
void animate_character(t_rpg *rpg, int dir);
int color_pixel_detector(t_rpg *rpg, int x_char, int y_char);
int test_next_move(t_rpg *rpg);

//move character
void move_down(t_rpg *rpg);
void move_up(t_rpg *rpg);
void move_left(t_rpg *rpg);
void move_right(t_rpg *rpg);

//dropped items
t_game_item *create_dropped_item(char *path_sp, sfVector2f pos, sfIntRect rect,
    int id);
void anim_items(t_rpg *rpg);
void get_dropped_item(t_rpg *rpg);

//tools
int check_character_in_window(t_rpg *rpg);
char *my_itoa(int nb);

//fight
void fightloop(t_rpg *rpg);
void init_fight(t_rpg *rpg);
void update_progression(t_rpg *rpg);
void draw_progress_bar(t_rpg *rpg);
void attack(t_rpg *rpg);
void mob_attack(t_rpg *rpg);

//centering tools
float get_center_y(t_rpg *rpg, t_obj *obj, float div_offset);
float get_center_x(t_rpg *rpg, t_obj *obj);
void center_obj(t_rpg *rpg, t_obj *obj);
void center_obj_yoffset(t_rpg *rpg, t_obj *obj, float y_offset);

//display
void display_items(t_rpg *rpg);
void display_backgroud(t_rpg *rpg);

//npc
int charac_can_interact(t_rpg *rpg, t_npc *npc);
void call_npc_interaction(t_rpg *rpg);
void display_npc_dialog(t_rpg *rpg);
void npc_event_listener(t_rpg *rpg);
void init_quentin(sfFont *font, t_npc **npc);
void init_enzo(sfFont *font, t_npc **npc);
void init_lea(sfFont *font, t_npc **npc);
void init_achille(sfFont *font, t_npc **npc);
void init_raoult(sfFont *font, t_npc **npc);

//npc dialogs
sfText **shopkeeper_init_dialog(sfFont *font);
sfText **enzo_init_dialog(sfFont *font);
sfText **lea_init_dialog(sfFont *font);
sfText **raoult_init_dialog(sfFont *font);
sfText **shopkeeper_init_alt_dialog(sfFont *font);
sfText **enzo_init_alt_dialog(sfFont *font);
sfText **lea_init_alt_dialog(sfFont *font);
sfText **raoult_init_alt_dialog(sfFont *font);

void init_npc(t_rpg *rpg);

//camera
void move_chunk_top(t_rpg *rpg);
void update_move_right(t_rpg *rpg);
void move_chunk_right(t_rpg *rpg);
void update_move_up(t_rpg *rpg);
void update_move_down(t_rpg *rpg);
void move_chunk_down(t_rpg *rpg);
void update_move_left(t_rpg *rpg);
void move_chunk_left(t_rpg *rpg);

//chunk tools
int get_top_from_chunk_y(t_rpg *rpg);
int get_left_from_chunk_x(t_rpg *rpg);

//mobs
void display_mobs(t_rpg *rpg);
void create_mob_bat(t_moblist *moblist, char *filepath, sfVector2f pos,
    int chunk[2]);
void create_mob_rat(t_moblist *moblist, char *filepath, sfVector2f pos,
    int chunk[2]);
void animate_bat(t_rpg *rpg);
void animate_sprite_bat(t_rpg *rpg);
void animate_sprite_rat(t_rpg *rpg);
void create_mobs_pos(t_moblist *moblist);

//particles
void animate_particle(t_rpg *rpg);
void display_attack_particle(t_rpg *rpg);
void spawn_attack_particle(t_rpg *rpg, sfSprite *on_sprite);

//input
void check_input(t_rpg *rpg);

//end game
void end_game(t_rpg *rpg);

#endif
