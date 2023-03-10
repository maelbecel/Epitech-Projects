##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for tetris
##

NAME         =		    lem_in

INCLUDE      =         	-I include/ -I include/lib/ -L lib/ -lmy -lmyprintf

CFLAGS      +=         	-Wall -Wextra -Werror -fvisibility=hidden $(INCLUDE)

SOURCES      =         	src/

SRC          =         	$(SOURCES)main.c 					\
						$(SOURCES)parser/read_input.c				\
						$(SOURCES)parser/my_str_to_word_array.c 	\
						$(SOURCES)parser/init.c					\
						$(SOURCES)parser/init_room.c				\
						$(SOURCES)parser/find_pos.c				\
						$(SOURCES)parser/tunnel.c					\
						$(SOURCES)parser/display_info.c			\
						$(SOURCES)parser/link.c					\
						$(SOURCES)parser/lemin.c	\
						$(SOURCES)parser/next.c

SRC			+=			$(SOURCES)solver/init_distance.c 	\
						$(SOURCES)solver/solver_display.c 	\
						$(SOURCES)solver/reset_visited.c 	\
						$(SOURCES)solver/solver.c

SRC_COUNT    =         	$(words $(SRC))

NB           =         	0

OBJ          =	        $(SRC:.c=.o)

TEMPFILES    =         *~ *vgcore* #*#

RM           =         rm -f

ECHO         =         /bin/echo -e
DEFAULT      =         "\033[00m"
BOLD         =         "\e[1m"
RED          =         "\e[31m"
GREEN        =         "\e[32m"
LIGHT_BLUE   =         "\e[94m"
WHITE        =         "\e[1;37m"

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

debug:		CFLAGS += -g3 -pg
debug:		all

clean:
			@make -C lib/my/ clean --no-print-directory
			@make -C lib/myprintf/ clean --no-print-directory
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@make -C lib/myprintf/ fclean --no-print-directory
			@make -C lib/my/ fclean --no-print-directory
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

re:
			@make fclean --no-print-directory
			@make --no-print-directory

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && /usr/bin/python3 \
			build/build.py $< $(NB) $(SRC_COUNT)

.PHONY: all re clean fclean debug
