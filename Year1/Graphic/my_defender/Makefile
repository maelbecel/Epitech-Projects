##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for my_defender
##

NAME         =		     my_defender

CSFML        =          -lcsfml-graphics -lcsfml-window \
						-lcsfml-system -lcsfml-audio

INCLUDE      =          -I include/ -I include/lib/ -L lib/ \
						-lmy -lmyprintf -lm $(CSFML)

CFLAGS      +=			-Wall -Wextra -Werror $(INCLUDE)

SOURCES      =          src/

DISPLAY      =          display/

EVENT        =          event/

INFO         =          info/

MONSTER      =          monster/

PAGE         =          page/

TOWER        =          tower/

ATTACK 		 = 			attack/

SRC          =			$(SOURCES)$(EVENT)builtin.c			    \
						$(SOURCES)$(INFO)createmap.c			\
						$(SOURCES)$(MONSTER)create_monster.c	\
						$(SOURCES)$(DISPLAY)display.c			\
						$(SOURCES)$(DISPLAY)draw.c				\
						$(SOURCES)$(DISPLAY)draw_text.c			\
						$(SOURCES)$(DISPLAY)draw_movement.c		\
						$(SOURCES)$(PAGE)game_page.c			\
						$(SOURCES)$(INFO)getsound.c				\
						$(SOURCES)$(EVENT)handle_click.c		\
						$(SOURCES)$(PAGE)help_page.c			\
						$(SOURCES)$(PAGE)info.c					\
						$(SOURCES)$(INFO)get_info.c				\
						$(SOURCES)$(INFO)getscore.c				\
						$(SOURCES)$(PAGE)init_scenes.c			\
						$(SOURCES)$(PAGE)init.c					\
						$(SOURCES)$(PAGE)main_menu_page.c		\
						$(SOURCES)main.c						\
						$(SOURCES)$(PAGE)pause_menu.c			\
						$(SOURCES)$(EVENT)analyse_event.c		\
						$(SOURCES)$(PAGE)menu.c					\
						$(SOURCES)$(PAGE)game_over.c			\
						$(SOURCES)$(TOWER)tower.c				\
						$(SOURCES)$(TOWER)create_tower.c		\
						$(SOURCES)$(TOWER)towers_attack.c		\
						$(SOURCES)$(TOWER)list.c				\
						$(SOURCES)$(MONSTER)monster.c			\
						$(SOURCES)$(TOWER)draw_tower.c			\
						$(SOURCES)$(MONSTER)create_directions.c	\
						$(SOURCES)$(MONSTER)check_dir.c			\
						$(SOURCES)$(TOWER)anim.c				\
						$(SOURCES)$(TOWER)menu_tower.c			\
						$(SOURCES)$(ATTACK)display_attack.c		\
						$(SOURCES)$(ATTACK)draw_attack.c		\

OBJ          =	        $(SRC:.c=.o)

SRC_COUNT   :=          $(words $(SRC))

NB           =          0

TEMPFILES    =          *~ *vgcore* #*#

RM           =          rm -f

ECHO         =          /bin/echo -e
DEFAULT      =          "\033[00m"
BOLD         =          "\e[1m"
RED          =          "\e[31m"
GREEN        =          "\e[32m"
LIGHT_BLUE   =          "\e[94m"
WHITE        =          "\e[1;37m"

all:	$(NAME)

$(NAME):	$(OBJ)
			@echo
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"SRC files sucessfully build. "$(DEFAULT))
			@make -C lib/my/ --no-print-directory
			@make -C lib/myprintf/ --no-print-directory
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) \
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

debug:		CFLAGS += -g3
debug:		all

clean:
			@make -C lib/my/ clean --no-print-directory
			@make -C lib/myprintf/ clean --no-print-directory
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@make -C lib/my/ fclean --no-print-directory
			@make -C lib/myprintf/ fclean --no-print-directory
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

re:
			@make fclean --no-print-directory
			@make --no-print-directory

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && python build/build.py $< $(NB) \
			$(SRC_COUNT)

.PHONY: all re clean fclean debug
.SILENT: re clean fclean all $(NAME)