##
## EPITECH PROJECT, 2019
## CPE_solostumper_1_2019
## File description:
## Makefile
##

SRC	=	src/npc/init_npc.c						\
		src/npc/init_alt_dialog.c				\
		src/npc/init_npcs.c						\
		src/npc/init_dialog.c					\
		src/npc/event_listener.c				\
		src/npc/npc_interaction.c				\
		src/npc/display_npc_dialog.c			\
		src/character/animate_character.c		\
		src/character/display_character.c		\
		src/character/init_character.c			\
		src/character/move_character.c			\
		src/character/move_input.c				\
		src/character/detection_moves.c			\
		src/display/display_gameloop.c			\
		src/hud/pause/init_pause.c				\
		src/hud/pause/display_pause.c			\
		src/hud/gameover/display_gameover.c		\
		src/hud/gameover/gameover_click.c		\
		src/fight/attack.c						\
		src/fight/fight.c						\
		src/fight/init_fight.c					\
		src/fight/progress_bar.c				\
		src/camera/chunk_move_up.c				\
		src/camera/chunk_move_right.c			\
		src/camera/chunk_move_left.c			\
		src/camera/chunk_move_down.c			\
		src/camera/chunk_tools.c				\
		src/inventory/init_inventory.c			\
		src/inventory/inventory.c				\
		src/inventory/utils_inventory.c			\
		src/inventory/display_inventory.c		\
		src/linkedlists/create_rm_free_elems.c	\
		src/linkedlists/list_tools.c			\
		src/linkedlists/swap_sort.c				\
		src/mainmenu/anim_btns.c				\
		src/mainmenu/anim_btns_pause.c			\
		src/mainmenu/btn_tools.c				\
		src/mainmenu/initmenu.c					\
		src/mainmenu/menu_click.c				\
		src/mainmenu/menuloop.c					\
		src/mainmenu/anim_btns_gameover.c		\
		src/mobs/bat.c							\
		src/mobs/rat.c							\
		src/mobs/animate_bat.c					\
		src/mobs/animate_rat.c					\
		src/scenes/events/home_events.c			\
		src/scenes/events/gameloop_events.c		\
		src/scenes/scene_manager.c				\
		src/scenes/scenes.c						\
		src/utils/center_obj.c					\
		src/utils/drawer.c						\
		src/utils/music.c						\
		src/utils/my_itoa.c						\
		src/utils/shape.c						\
		src/utils/sprite.c						\
		src/utils/text.c						\
		src/create_object.c						\
		src/items/dropped_items.c				\
		src/items/anim_items.c					\
		src/items/get_items.c					\
		src/hud/display_hud.c					\
		src/hud/pause/menu_pause_click.c		\
		src/quests/init_quests.c				\
		src/quests/display_quests.c				\
		src/audio/init_audio.c					\
		src/particles/particles.c				\
		src/xp/manage_xp.c						\
		src/game.c								\
		src/utils/end_game.c					\
		src/hitbox.c							\
		src/init_game.c							\
		src/init_mobs_map.c						\
		src/init_items.c						\
		src/create_background.c					\
		src/destroyer.c							\
		src/main.c

OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-L lib/my -lmy -lm -I include/ -Wextra -Wall -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -g

NAME	=		my_rpg

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm	-f 	$(OBJ)
	make clean -C lib/my

fclean: clean
	rm 	-f 	$(NAME)
	make fclean -C lib/my

re:	fclean	all